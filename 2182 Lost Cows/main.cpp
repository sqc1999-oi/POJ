#include <iostream>
#include <algorithm>
using namespace std;
int t[8001], p[8001], ans[8001], n;
int lowbit(int x) { return x&-x; }
void update(int p, int val)
{
	while (p <= n)
	{
		t[p] += val;
		p += lowbit(p);
	}
}
int query(int p)
{
	int ans = 0;
	while (p > 0)
	{
		ans += t[p];
		p -= lowbit(p);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 2; i <= n; i++) cin >> p[i];
	ans[n] = p[n] + 1;
	update(ans[n], 1);
	for (int i = n - 1; i > 0; i--)
	{
		int l = 1, r = n, res;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int x = mid - 1 - query(mid - 1);
			if (x <= p[i]) l = mid + 1, res = mid;
			else r = mid - 1;
		}
		ans[i] = res;
		update(res, 1);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}
