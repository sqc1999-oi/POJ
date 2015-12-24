#include <iostream>
#include <algorithm>
using namespace std;
int a[5001];
int f[5001], cnt[5001];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], f[i] = 1, cnt[i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i] < a[j])
			{
				if (f[i] < f[j] + 1)
				{
					f[i] = f[j] + 1;
					cnt[i] = cnt[j];
				}
				else if (f[i] == f[j] + 1) cnt[i] += cnt[j];
			}
		}
		for (int j = i - 1; j > 0; j--)
		{
			if (a[i] == a[j] && f[i] == f[j])
			{
				cnt[j] = 0;
				break;
			}
		}
	}
	int len = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] > len)
		{
			len = f[i];
			ans = cnt[i];
		}
		else if (f[i] == len) ans += cnt[i];
	}
	cout << len << ' ' << ans;
}
