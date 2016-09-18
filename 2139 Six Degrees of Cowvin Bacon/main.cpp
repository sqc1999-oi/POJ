#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int g[301][301];
int main()
{
	ios::sync_with_stdio(false);
	memset(g, 0x3f, sizeof(g));
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		vector<int> v;
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		for (int j = 0; j < x; j++)
		{
			for (int k = j + 1; k < x; k++)
			{
				g[v[j]][v[k]] = g[v[k]][v[j]] = 1;
			}
		}
	}			
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	int ans = 0x7fffffff;
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i != j) tmp += g[i][j];
		}
		ans = min(ans, tmp);
	}
	cout << ans * 100 / (n - 1) << endl;
}
