#include<iostream>
#include<algorithm>
using namespace std;
bool map[101][101];
const pair<int, int> P[] = { {0,1},{1,0},{-1,0},{0,-1} };
pair<int, int> operator + (pair<int, int> a, pair<int, int> b) { return make_pair(a.first + b.first, a.second + b.second); }
int n, m;
int dfs(pair<int, int> p)
{
	map[p.first][p.second] = false;
	int ans = 1;
	for (int i = 0; i < 4; i++)
	{
		pair<int, int> tmp = p + P[i];
		if (tmp.first > 0 && tmp.first <= n&&tmp.second > 0 && tmp.second <= m&&map[tmp.first][tmp.second])
		{
			ans += dfs(tmp);
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
	{
		int r, c;
		cin >> r >> c;
		map[r][c] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j]) ans = max(ans, dfs(make_pair(i, j)));
		}
	}
	cout << ans << endl;
}
