#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Edge { int From, To, Pow; };
vector<Edge> G[501];
int dis[501], cnt[501];
bool inq[501], vis[501];
bool Spfa(int s, int n)
{
	memset(dis, 0x3f, sizeof dis);
	memset(inq, 0, sizeof inq);
	memset(cnt, 0, sizeof cnt);
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	inq[s] = true;
	cnt[s] = 1;
	vis[s] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = 0; i < G[u].size(); i++)
		{
			Edge &e = G[u][i];
			vis[e.To] = true;
			int tmp = dis[e.To];
			dis[e.To] = min(dis[e.To], dis[e.From] + e.Pow);
			if (tmp != dis[e.To] && !inq[e.To])
			{
				if (++cnt[e.To] == n) return false;
				q.push(e.To);
				inq[e.To] = true;
			}
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	int f;
	cin >> f;
	for (int i = 1; i <= f; i++)
	{
		int n, m, w;
		cin >> n >> m >> w;
		for (int j = 1; j <= n; j++) G[j].clear();
		for (int j = 1; j <= m; j++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			G[s].push_back(Edge{ s,e,t });
			G[e].push_back(Edge{ e,s,t });
		}
		for (int j = 1; j <= w; j++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			G[s].push_back(Edge{ s,e,-t });
		}
		memset(vis, 0, sizeof vis);
		bool x = false;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i] && !Spfa(i, n))
			{
				x = true;
				break;
			}
		}
		cout << (x ? "YES" : "NO") << endl;
	}
}
