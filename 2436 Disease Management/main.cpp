#include <iostream>
#include <algorithm>
using namespace std;
int a[1001], ans, n, d, k;
void dfs(int cnt, int x, int s)
{
	if (cnt == k)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if ((a[i] & s) == a[i])
			{
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	else if (x <= d)
	{
		dfs(cnt + 1, x + 1, s | (1 << (x - 1)));
		dfs(cnt, x + 1, s);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> d >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++)
		{
			int xx;
			cin >> xx;
			a[i] |= (1 << (xx - 1));
		}
	}
	dfs(0, 1, 0);
	cout << ans;
}
