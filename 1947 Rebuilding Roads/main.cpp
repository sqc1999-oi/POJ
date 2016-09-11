#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> G[151];
int f[151][151], cnt[151], ans = 0x7fffffff, p;

int dfs(int u)
{
	cnt[u] = 1;
	for (int i = 0; i < G[u].size(); i++) cnt[u] += dfs(G[u][i]);
	f[u][1] = G[u].size();
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		for (int j = cnt[u]; j > 0; j--)
		{
			for (int k = 1; k < j && k <= cnt[v]; k++)
			{
				f[u][j] = min(f[u][j], f[u][j - k] + f[v][k] - 1);
			}
		}
	}
	if (cnt[u] >= p) ans = min(ans, f[u][p] + (u != 1));
	return cnt[u];
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> p;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	memset(f, 0x3f, sizeof f);
	dfs(1);
	cout << ans;
}
