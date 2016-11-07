#include <iostream>
#include <algorithm>
using namespace std;
long long f[1001][101][2];
const long long INF = (long long)1e18;
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= k; i++) f[0][i][0] = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j - i < 0)
			{
				f[j][i][0] = f[j][i - 1][0];
				f[j][i][1] = f[j][i - 1][1];
			}
			else
			{
				f[j][i][1] = f[j][i - 1][1] + f[j - i][i][1] + (f[j][i - 1][0] + f[j - i][i][0]) / INF;
				f[j][i][0] = (f[j][i - 1][0] + f[j - i][i][0]) % INF;
			}
		}
	}
	if (f[n][k][1]>0) cout << f[n][k][1];
	cout << f[n][k][0];
}
