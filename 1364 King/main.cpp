#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

struct Edge
{
	int To, Pow, Next;

	Edge(int to, int pow, int next) :
		To(to), Pow(pow), Next(next) { }

	Edge() { }
} E[10000];

int G[1000], dis[1000], cnt, Cnt[1000];
bool inq[1000];

void AddEdge(int from, int to, int pow)
{
	E[++cnt] = Edge(to, pow, G[from]);
	G[from] = cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		cnt = 0;
		memset(G, 0, sizeof G);
		for (int i = 1; i <= n + 1; i++)
			AddEdge(0, i, 0);
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++)
		{
			int a, b, c;
			string s;
			cin >> a >> b >> s >> c;
			b = a + b + 1;
			if (s == "gt")
			{
				swap(a, b);
				c = -c;
			}
			AddEdge(a, b, c - 1);
		}
		memset(dis, 0x3f, sizeof dis);
		memset(inq, 0, sizeof inq);
		memset(Cnt, 0, sizeof Cnt);
		dis[0] = 0;
		queue<int> q;
		q.push(0);
		inq[0] = true;
		bool flag = true;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = false;
			for (int i = G[u]; i != 0; i = E[i].Next)
			{
				int &v = E[i].To;
				int tmp = dis[v];
				dis[v] = min(dis[v], dis[u] + E[i].Pow);
				if (tmp != dis[v] && !inq[v])
				{
					if (++Cnt[v] > n + 2)
					{
						flag = false;
						break;
					}
					q.push(v);
					inq[v] = true;
				}
				if (!flag) break;
			}
		}
		cout << (flag ? "lamentable kingdom" : "successful conspiracy") << endl;
	}
}
