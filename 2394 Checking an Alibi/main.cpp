#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Edge { int From, To, Pow; };
int pos[101], dis[501];
bool inq[501];
vector<Edge> G[501];
int main()
{
	ios::sync_with_stdio(false);
	int f, p, c, m;
	cin >> f >> p >> c >> m;
	for (int i = 1; i <= p; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back(Edge{ u,v,w });
		G[v].push_back(Edge{ v,u,w });
	}
	for (int i = 1; i <= c; i++) cin >> pos[i];
	queue<int> q;
	q.push(1);
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	inq[1] = true;
	while (!q.empty())
	{
		int u = q.front();
		inq[u] = false;
		q.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			Edge &e = G[u][i];
			int tmp = dis[e.To];
			dis[e.To] = min(dis[e.To], dis[e.From] + e.Pow);
			if (tmp != dis[e.To] && !inq[e.To])
			{
				q.push(e.To);
				inq[e.To] = true;
			}
		}
	}
	vector<int> v;
	for (int i = 1; i <= c; i++)
	{
		if (dis[pos[i]] <= m) v.push_back(i);
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}
