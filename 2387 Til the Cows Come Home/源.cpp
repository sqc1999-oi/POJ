#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Edge { int from, to, pow; };
vector<Edge> Edges;
vector<int> G[1001];
bool inq[1001];
int dis[1001];
int main()
{
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t >> n;
	for (int i = 1; i <= t; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back(Edges.size());
		Edges.push_back(Edge{ a,b,c });
		G[b].push_back(Edges.size());
		Edges.push_back(Edge{ b,a,c });
	}
	fill(dis + 1, dis + 1 + n, 0x7fffffff);
	queue<int> q;
	q.push(n);
	inq[n] = true;
	dis[n] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		inq[x] = false;
		for (int i = 0; i < G[x].size(); i++)
		{
			Edge &e = Edges[G[x][i]];
			int tmp = dis[e.to];
			dis[e.to] = min(dis[e.to], dis[e.from] + e.pow);
			if (!inq[e.to] && tmp != dis[e.to])
			{
				q.push(e.to);
				inq[e.to] = true;
			}
		}
	}
	cout << dis[1] << endl;
}
