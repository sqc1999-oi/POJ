#include <iostream>
#include <algorithm>

using namespace std;
int c[100001], n, m;

bool check(int limit)
{
	int pos = 0;
	for (int i = 1; i <= m; i++)
	{
		int sum = 0;
		while (pos < n && sum + c[pos + 1] <= limit) sum += c[++pos];
	}
	return pos == n;
}

int main()
{
	ios::sync_with_stdio(false);
	int l = 0, r = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i], r += c[i], l = max(l, c[i]);
	int ans = r;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans;
}
