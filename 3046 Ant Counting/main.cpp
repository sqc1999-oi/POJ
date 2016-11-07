#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int f[2][100001], n[1001];
int main()
{
	ios::sync_with_stdio(false);
	int t, a, s, b;
	cin >> t >> a >> s >> b;
	for (int i = 1; i <= a; i++)
	{
		int x;
		cin >> x;
		n[x]++;
	}
	int cu = 0, tot = 0;
	f[1][0] = 1;
	for (int i = 1; i <= t; i++)
	{
		tot += n[i];
		for (int k = 0; k <= n[i]; k++)
		{
			for (int j = tot; j >= k; j--)
			{
				(f[cu][j] += f[cu ^ 1][j - k]) %= 1000000;
			}
		}
		cu ^= 1;
		memset(f[cu], 0, sizeof f[cu]);
	}
	int ans = 0;
	for (int i = s; i <= b; i++)
	{
		(ans += f[cu ^ 1][i]) %= 1000000;
	}
	cout << ans;
}
