#include <iostream>
#include <algorithm>
using namespace std;
int v[2001], f[2001][2001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j + i - 1 <= n; j++)
		{
			if (j + i <= n) f[j][i] = max(f[j][i], f[j][i + 1] + v[j + i] * (n - i));
			if (j > 1) f[j][i] = max(f[j][i], f[j - 1][i + 1] + v[j - 1] * (n - i));
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, f[i][0]);
	cout << ans;
}
