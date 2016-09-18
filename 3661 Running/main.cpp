#include <iostream>
#include <algorithm>

using namespace std;
int d[10001], f[10001][501];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m && j <= i; j++)
		{
			f[i][j] = f[i - 1][j - 1] + d[i];
		}
		f[i][0] = f[i - 1][0];
		for (int j = 1; j <= m && i - j >= j; j++)
		{
			f[i][0] = max(f[i][0], f[i - j][j]);
		}
	}
	cout << f[n][0] << endl;
}
