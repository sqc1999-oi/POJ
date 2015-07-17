#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> G[3001];
int cost[3001], val[3001], f[3001][3001];

int dfs(int u)
{
	f[u][0] = 0;
	if (G[u].empty()) return f[u][1] = val[u], 1;
	int sum = 0;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		int x = dfs(v);
		sum += x;
		for (int j = sum; j > 0; j--)
		{
			for (int k = 0; k <= x && k <= j; k++)
			{
				f[u][j] = max(f[u][j], f[u][j - k] + f[v][k] - cost[v]);
			}
		}
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n - m; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a;
			cin >> a;
			cin >> cost[a];
			G[i].push_back(a);
		}
	}
	for (int i = n - m + 1; i <= n; i++) cin >> val[i];
	memset(f, 0x90, sizeof f);
	dfs(1);
	for (int i = m; i >= 0; i--)
		if (f[1][i] >= 0)
		{
			cout << i << endl;
			break;
		}
}