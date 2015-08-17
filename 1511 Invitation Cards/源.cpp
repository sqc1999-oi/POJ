#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
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
} E[2][1000001];

int G[2][1000001], dis[2][1000001], cnt;
bool inq[2][1000001];

void AddEdge(int from, int to, int pow)
{
	cnt++;
	E[0][cnt] = Edge(to, pow, G[0][from]);
	G[0][from] = cnt;
	E[1][cnt] = Edge(from, pow, G[1][to]);
	G[1][to] = cnt;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		cnt = 0;
		memset(G, 0, sizeof G);
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			AddEdge(a, b, c);
		}
		long long ans = 0;
		for (int k = 0; k <= 1; k++)
		{
			fill(dis[k] + 1, dis[k] + 1 + n, INT_MAX);
			dis[k][1] = 0;
			queue<int> q;
			q.push(1);
			inq[k][1] = true;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				inq[k][u] = false;
				for (int i = G[k][u]; i != 0; i = E[k][i].Next)
				{
					int &v = E[k][i].To;
					int tmp = dis[k][v];
					dis[k][v] = min(dis[k][v], dis[k][u] + E[k][i].Pow);
					if (tmp != dis[k][v] && !inq[k][v])
					{
						q.push(v);
						inq[k][v] = true;
					}
				}
			}
			for (int i = 2; i <= n; i++)
				ans += dis[k][i];
		}
		printf("%lld\n", ans);
	}
}
