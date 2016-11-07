#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int main()
{
	ios::sync_with_stdio(false);
	int n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 0, r = a[n], ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int cnt = 1, len = 0;
		for (int i = 2; i <= n; i++)
		{
			len += a[i] - a[i - 1];
			if (len >= mid)
			{
				cnt++;
				len = 0;
			}
		}
		if (cnt < c) r = mid - 1;
		else
		{
			ans = mid;
			l = mid + 1;
		}
	}
	cout << ans;
}
