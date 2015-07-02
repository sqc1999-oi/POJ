#include <iostream>
#include <algorithm>
using namespace std;
struct cow { int w, s; } a[50001];
bool cmp(const cow &a, const cow &b) { return a.w + a.s < b.w + b.s; }
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].s;
	sort(a + 1, a + 1 + n, cmp);
	int ans = -0x3f3f3f3f, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, sum - a[i].s);
		sum += a[i].w;
	}
	cout << ans << endl;
}