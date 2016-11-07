#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
struct Edge
{
	int From, To, Pow;
};
vector<int> G[1001];
vector<Edge> Edges;
int dis[1001];
bool inq[1001];

int Spfa(int s, int t, int limit)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	inq[s] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		inq[x] = false;
		for (int i = 0; i < G[x].size(); i++)
		{
			Edge &e = Edges[G[x][i]];
			int tmp = dis[e.To];
			dis[e.To] = min(dis[e.To], dis[e.From] + (e.Pow > limit ? 1 : 0));
			if (tmp != dis[e.To] && !inq[e.To])
			{
				q.push(e.To);
				inq[e.To] = true;
			}
		}
	}
	return dis[t];
}

int main()
{
	ios::sync_with_stdio(false);
	int n, p, k, maxlen = 0;
	cin >> n >> p >> k;
	for (int i = 1; i <= p; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		maxlen = max(maxlen, l);
		G[a].push_back(Edges.size());
		Edges.push_back(Edge{ a, b, l });
		G[b].push_back(Edges.size());
		Edges.push_back(Edge{ b, a, l });
	}
	int l = 0, r = maxlen + 2, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (Spfa(1, n, mid) <= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << (l > maxlen ? -1 : ans) << endl;
}
