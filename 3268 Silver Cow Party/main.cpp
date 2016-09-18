#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Edge { int From, To, Pow; };
vector<Edge> G[2][1001];
int dis[2][1001];
bool inq[1001];
void Spfa(int s,int flag)
{
	memset(dis[flag], 0x3f, sizeof(dis[flag]));
	dis[flag][s] = 0;
	inq[s] = true;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = 0; i < G[flag][u].size(); i++)
		{
			Edge &e = G[flag][u][i];
			int tmp = dis[flag][e.To];
			dis[flag][e.To] = min(dis[flag][e.To], dis[flag][e.From] + e.Pow);
			if (tmp != dis[flag][e.To] && !inq[e.To])
			{
				q.push(e.To);
				inq[e.To] = true;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		G[0][a].push_back(Edge{ a,b,t });
		G[1][b].push_back(Edge{ b,a,t });
	}
	Spfa(x, 0);
	Spfa(x, 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dis[0][i] != 0x3f3f3f3f && dis[1][i] != 0x3f3f3f3f)
			ans = max(ans, dis[0][i] + dis[1][i]);
	}
	cout << ans << endl;
}
