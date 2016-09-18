#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int cow[101], cnt[1001];
bool vis[1001];
vector<int> G[1001];
void dfs(int u)
{
	vis[u] = true;
	cnt[u]++;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!vis[v]) dfs(v);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int k, n, m;
	cin >> k >> n >> m;
	for (int i = 1; i <= k; i++) cin >> cow[i];
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	for (int i = 1; i <= k; i++)
	{
		memset(vis, 0, sizeof(vis));
		dfs(cow[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == k) ans++;
	}
	cout << ans;
}
