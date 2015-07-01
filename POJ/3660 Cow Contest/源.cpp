#include <iostream>
#include <algorithm>

using namespace std;
bool dis[101][101];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		dis[a][b] = true;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = dis[i][j] || (dis[i][k] && dis[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++) cnt += dis[i][j] + dis[j][i];
		if (cnt == n - 1) ans++;
	}
	cout << ans << endl;
}