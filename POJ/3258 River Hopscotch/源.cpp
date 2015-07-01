#include <iostream>
#include <algorithm>
using namespace std;
int d[50002], n, m;
bool check(int limit)
{
	int pos = 0, cnt = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		if (d[i] - d[pos] < limit) cnt++;
		else pos = i;
	}
	return cnt <= m;
}
int main()
{
	ios::sync_with_stdio(false);
	int l;
	cin >> l >> n >> m;
	d[n + 1] = l;
	for (int i = 1; i <= n; i++) cin >> d[i];
	sort(d + 1, d + 1 + n);
	int ans = 0, L = 0, R = l;
	while (L <= R)
	{
		int mid = (L + R) / 2;
		if (check(mid)) ans = mid, L = mid + 1;
		else R = mid - 1;
	}
	cout << ans;
}