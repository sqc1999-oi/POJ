#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
struct Edge
{
	int From, To, Cap, Flow;
};
const int INF = 0x3f3f3f3f;
int dis[300][300], a[300], p[300];
vector<int> G[300];
vector<Edge> Edges;

int MaxFlow(int s, int t, int limit)
{
	for (int i = 0; i < Edges.size(); i++) Edges[i].Flow = 0;
	int flow = 0;
	while (true)
	{
		memset(a, 0, sizeof(a));
		a[s] = INF;
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < G[x].size(); i++)
			{
				Edge &e = Edges[G[x][i]];
				if (dis[e.From][e.To] <= limit && !a[e.To] && e.Cap > e.Flow)
				{
					p[e.To] = G[x][i];
					a[e.To] = min(a[e.From], e.Cap - e.Flow);
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

void AddEdge(int from, int to, int cap)
{
	G[from].push_back(Edges.size());
	Edges.push_back(Edge{from, to, cap, 0});
	G[to].push_back(Edges.size());
	Edges.push_back(Edge{to, from, 0, 0});
}

int main()
{
	ios::sync_with_stdio(false);
	int k, c, m, l = 0, r = 0;
	cin >> k >> c >> m;
	int n = k + c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> dis[i][j];
			if (dis[i][j] == 0) dis[i][j] = INF;
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) r = max(r, dis[i][j]);
	for (int i = k + 1; i <= n; i++)
	{
		AddEdge(0, i, 1);
		for (int j = 1; j <= k; j++) AddEdge(i, j, 1);
	}
	for (int i = 1; i <= k; i++) AddEdge(i, n + 1, m);
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (MaxFlow(0, n + 1, mid) >= c) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
}
