#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 0x7fffffff;
struct Edge { int From, To, Cap, Flow; };
int a[1002], p[1002];
vector<Edge> Edges;
vector<int> G[1002];
void AddEdge(int from, int to, int cap)
{
	G[from].push_back(Edges.size());
	Edges.push_back(Edge{ from,to,cap,0 });
	G[to].push_back(Edges.size());
	Edges.push_back(Edge{ to,from,0,0 });
}
int MaxFlow(int s, int t)
{
	int flow = 0;
	while (true)
	{
		memset(a, 0, sizeof a);
		queue<int> q;
		q.push(s);
		a[s] = INF;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = Edges[G[u][i]];
				if (!a[e.To] && e.Cap>e.Flow)
				{
					a[e.To] = min(a[e.From], e.Cap - e.Flow);
					p[e.To] = G[u][i];
					q.push(e.To);
				}
			}
			if (a[t]) break;
		}
		if (!a[t]) break;
		for (int u = t; u != s; u = Edges[p[u]].From)
		{
			Edges[p[u]].Flow += a[t];
			Edges[p[u] ^ 1].Flow -= a[t];
		}
		flow += a[t];
	}
	return flow;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		int r, c;
		cin >> r >> c;
		AddEdge(r, c + n, 1);
	}
	for (int i = 1; i <= n; i++) AddEdge(0, i, 1);
	for (int i = n + 1; i <= n * 2; i++) AddEdge(i, n * 2 + 1, 1);
	cout <<	MaxFlow(0, n * 2 + 1);
}