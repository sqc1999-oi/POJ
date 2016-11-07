#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 0x3f3f3f3f;
int f[22][101][101];

int main()
{
	ios::sync_with_stdio(false);
	int n, e, d;
	cin >> n >> e >> d;
	memset(f, 0x3f, sizeof f);
	f[1][0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= d; j++)
		{
			for (int k = 0; k <= e; k++)
			{
				if (f[i][j][k] != INF)
				{
					for (int x = 0; j + x <= d && k + x * x <= e; x++)
					{
						f[i][j + x][k + x * x] = min(f[i][j + x][k + x * x], f[i][j][k] + 1);
					}
					f[i + 1][j][j] = min(f[i + 1][j][j], f[i][j][k]);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= e; i++)
	{
		ans = min(ans, f[n][d][i]);
	}
	cout << ans;
}
