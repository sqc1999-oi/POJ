#include <iostream>
#include <algorithm>

using namespace std;

struct cow
{
	int t, d;

	bool operator<(const cow &a) const
	{
		return 2 * t * a.d < 2 * a.t * d;
	}
} a[100001];

long long sum[100002];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].t >> a[i].d;
	sort(a + 1, a + 1 + n);
	for (int i = n; i > 0; i--) sum[i] = sum[i + 1] + a[i].d;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += a[i].t * 2 * sum[i + 1];
	}
	cout << ans;
}
