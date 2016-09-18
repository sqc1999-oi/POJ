#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct Node
{
	int From, To, Pow, Next;
} E[200001];

int G[5001], cnt;

void AddEdge(int from, int to, int pow)
{
	E[++cnt] = Node{from, to, pow, G[from]};
	G[from] = cnt;
}

int dis[2][5001];
bool inq[5001];

void Spfa(int s, int f)
{
	memset(dis[f], 0x3f, sizeof dis[f]);
	dis[f][s] = 0;
	inq[s] = true;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = G[u]; i != 0; i = E[i].Next)
		{
			int tmp = dis[f][E[i].To];
			dis[f][E[i].To] = min(dis[f][E[i].To], dis[f][u] + E[i].Pow);
			if (tmp != dis[f][E[i].To] && !inq[E[i].To])
			{
				q.push(E[i].To);
				inq[E[i].To] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= r; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		AddEdge(a, b, d);
		AddEdge(b, a, d);
	}
	Spfa(1, 0);
	Spfa(n, 1);
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= cnt; i++)
	{
		int x = dis[0][E[i].From] + E[i].Pow + dis[1][E[i].To];
		if (x > dis[0][n] && x < ans) ans = x;
	}
	cout << ans;
}
