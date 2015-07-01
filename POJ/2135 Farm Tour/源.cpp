#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 2001;
struct Edge
{
	int from, to, cap, flow, cost;
};
struct MCMF
{
	vector<Edge> Edges;
	vector<int> G[MAXN];
	bool inq[MAXN];
	int n, d[MAXN], p[MAXN], a[MAXN];
	void AddEdge(int from, int to, int cap, int cost)
	{
		G[from].push_back(Edges.size());
		Edges.push_back(Edge{ from, to, cap, 0, cost });
		G[to].push_back(Edges.size());
		Edges.push_back(Edge{ to, from, 0, 0, -cost });
	}
	bool BellmanFord(int s, int t, int flow_limit, int &flow, int &cost)
	{
		for (int i = 0; i <= n; i++) d[i] = INF;
		memset(inq, 0, sizeof(inq));
		d[s] = 0;
		inq[s] = true;
		p[s] = 0;
		a[s] = INF;
		queue<int> Q;
		Q.push(s);
		while (!Q.empty())
		{
			int u = Q.front(); Q.pop();
			inq[u] = false;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = Edges[G[u][i]];
				if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
				{
					d[e.to] = d[u] + e.cost;
					p[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if (!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to] = true;
					}
				}
			}
		}
		if (d[t] == INF) return false;
		if (flow + a[t] > flow_limit) a[t] = flow_limit - flow;
		flow += a[t];
		cost += d[t] * a[t];
		for (int u = t; u != s; u = Edges[p[u]].from)
		{
			Edges[p[u]].flow += a[t];
			Edges[p[u] ^ 1].flow -= a[t];
		}
		return true;
	}
	int MincostFlow(int s, int t, int flow_limit, int &cost)
	{
		int flow = 0;
		cost = 0;
		while (flow < flow_limit && BellmanFord(s, t, flow_limit, flow, cost));
		return flow;
	}
};
MCMF mc;
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	mc.n = n;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		mc.AddEdge(a, b, 1, c);
		mc.AddEdge(b, a, 1, c);
	}
	int cost;
	mc.MincostFlow(1, n, 2, cost);
	cout << cost << endl;
}