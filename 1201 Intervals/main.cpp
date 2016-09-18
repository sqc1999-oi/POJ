#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

struct Edge
{
	int To, Pow, Next;

	Edge(int to, int pow, int next) :
		To(to), Pow(pow), Next(next) { }

	Edge() { }
} E[500001];

int G[50001], dis[50001], cnt;
bool inq[50001];

void AddEdge(int from, int to, int pow)
{
	E[++cnt] = Edge(to, pow, G[from]);
	G[from] = cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a++;
		b++;
		m = max(m, b);
		AddEdge(a - 1, b, c);
	}
	for (int i = 0; i <= m; i++)
	{
		AddEdge(i - 1, i, 0);
		AddEdge(i, i - 1, -1);
	}
	fill(dis, dis + 1 + n, INT_MIN);
	dis[0] = 0;
	queue<int> q;
	q.push(0);
	inq[0] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = G[u]; i != 0; i = E[i].Next)
		{
			int &v = E[i].To;
			int tmp = dis[v];
			dis[v] = max(dis[v], dis[u] + E[i].Pow);
			if (tmp != dis[v] && !inq[v])
			{
				q.push(v);
				inq[v] = true;
			}
		}
	}
	cout << dis[m];
}
