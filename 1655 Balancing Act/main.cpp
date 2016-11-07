#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> G[20001];
int s[20001];

int dfs(int u, int fa, int n)
{
	s[u] = 0;
	int sum = 1;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (v != fa)
		{
			int x = dfs(v, u, n);
			sum += x;
			s[u] = max(s[u], x);
		}
	}
	s[u] = max(s[u], n - sum);
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(1, 0, n);
		int pos, ans = 0x7fffffff;
		for (int i = 1; i <= n; i++)
		{
			if (s[i] < ans)
			{
				ans = s[i];
				pos = i;
			}
		}
		cout << pos << ' ' << ans << endl;
	}
}
