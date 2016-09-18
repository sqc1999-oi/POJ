#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct coin { int v, b; } a[21];
int need[21];
bool cmp(const coin &a, const coin &b) { return a.v < b.v; }
int main()
{
	ios::sync_with_stdio(false);
	int n, c, ans = 0;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> a[i].v >> a[i].b;
	sort(a + 1, a + 1 + n, cmp);
	for (int i = n; i > 0; i--)
	{
		if (a[i].v >= c) ans += a[i].b, n--;
		else break;
	}
	while (true)
	{
		int remain = c;
		memset(need, 0, sizeof need);
		for (int i = n; i > 0; i--)
		{
			int tmp = remain / a[i].v;
			tmp = min(a[i].b, tmp);
			need[i] = tmp;
			remain -= tmp*a[i].v;
		}
		if (remain > 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i].b > 0 && a[i].v >= remain)
				{
					need[i]++;
					remain = 0;
					break;
				}
			}
		}
		if (remain > 0) break;
		int cnt = 0x7fffffff;
		for (int i = 1; i <= n; i++)
		{
			if (need[i] > 0)
			{
				cnt = min(a[i].b / need[i], cnt);
			}
		}
		ans += cnt;
		for (int i = 1; i <= n; i++) a[i].b -= cnt*need[i];
	}
	cout << ans << endl;
}
