#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Edge { int from, to, cap, flow; };
struct EK
{
	static const int INF = 0x7fffffff;
	int n, m, a[201], p[201];
	vector<int> G[201];
	vector<Edge> Edges;
	int MaxFlow()
	{
		int flow = 0;
		while (true)
		{
			fill(a + 1, a + 1 + m, 0);
			a[1] = INF;
			queue<int> q;
			q.push(1);
			while (!q.empty())
			{
				int x = q.front();
				q.pop();
				for (int i = 0; i < G[x].size(); i++)
				{
					Edge &e = Edges[G[x][i]];
					if (!a[e.to] && e.cap>e.flow)
					{
						a[e.to] = min(a[x], e.cap - e.flow);
						p[e.to] = G[x][i];
						q.push(e.to);
					}
				}
				if (a[m]) break;
			}
			if (!a[m]) break;
			for (int u = m; u != 1; u = Edges[p[u]].from)
			{
				Edges[p[u]].flow += a[m];
				Edges[p[u] ^ 1].flow -= a[m];
			}
			flow += a[m];
		}
		return flow;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		EK ek;
		ek.n = n, ek.m = m;
		for (int i = 1; i <= n; i++)
		{
			int s, e, c;
			cin >> s >> e >> c;
			ek.G[s].push_back(ek.Edges.size());
			ek.Edges.push_back(Edge{ s,e,c,0 });
			ek.G[e].push_back(ek.Edges.size());
			ek.Edges.push_back(Edge{ e,s,0,0 });
		}
		cout << ek.MaxFlow() << endl;
	}
}
