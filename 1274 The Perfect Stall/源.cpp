#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int INF = 0x7fffffff;
struct edge
{
	int from, to, cap, flow;
};
int n, m;
vector<edge> es;
vector<int> g[402];
int a[402], p[402];
int ek()
{
	int flow = 0;
	while (true)
	{
		memset(a, 0, sizeof(a));
		queue<int> q;
		q.push(0);
		a[0] = INF;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < g[x].size(); i++)
			{
				edge &e = es[g[x][i]];
				if (!a[e.to] && e.cap>e.flow)
				{
					p[e.to] = g[x][i];
					a[e.to] = min(a[x], e.cap - e.flow);
					q.push(e.to);
				}
			}
			if (a[n + m + 1]) break;
		}
		if (!a[n + m + 1]) break;
		for (int u = n + m + 1; u != 0; u = es[p[u]].from)
		{
			es[p[u]].flow += a[n + m + 1];
			es[p[u] ^ 1].flow -= a[n + m + 1];
		}
		flow += a[n + m + 1];
	}
	return flow;
}
void addedge(int x, int y)
{
	edge e;
	e = { x,y,1,0 };
	g[x].push_back(es.size());
	es.push_back(e);
	e = { y,x,0,0 };
	g[y].push_back(es.size());
	es.push_back(e);
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			addedge(0, i);
			int x;
			cin >> x;
			for (int j = 1; j <= x; j++)
			{
				int xx;
				cin >> xx;
				addedge(i, xx + n);
			}
		}
		for (int i = 1; i <= m; i++) addedge(i + n, n + m + 1);
		cout << ek() << endl;
		es.clear();
		for (int i = 0; i <= n + m + 1; i++) g[i].clear();
	}
}