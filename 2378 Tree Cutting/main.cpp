#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> G[10000];
int cnt[10000], n;
static int dfs(int u, int fa)
{
	int ans = 1;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (v != fa)
		{
			int x = dfs(v, u);
			cnt[u] = max(cnt[u], x);
			ans += x;
		}
	}
	cnt[u] = max(cnt[u], n - ans);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0, -1);
	bool b = false;
	for (int i = 0; i < n; i++)
	{
		if (cnt[i] <= n / 2)
		{
			b = true;
			cout << i + 1 << endl;
		}
	}
	if (!b) cout << "NONE" << endl;
}
