#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int t[10001], dis[10001], in[10001];
vector<int> G[10001];
queue<int> q;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		cin >> in[i];
		if (in[i] == 0) q.push(i);
		else
		{
			for (int j = 1; j <= in[i]; j++)
			{
				int x;
				cin >> x;
				G[x].push_back(i);
			}
		}
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			dis[v] = max(dis[v], dis[u] + t[u]);
			if (--in[v] == 0) q.push(v);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dis[i] + t[i]);
	cout << ans;
}