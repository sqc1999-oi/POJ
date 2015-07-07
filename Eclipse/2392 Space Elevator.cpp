#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct cube
{
	int h, a, c;
	bool operator <(const cube &b) const
	{
		return a < b.a;
	}
} a[401];
bool f[40001];
int cnt[40001];
int main()
{
	ios::sync_with_stdio(false);
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> a[i].h >> a[i].a >> a[i].c;
	sort(a + 1, a + 1 + k);
	f[0] = true;
	int ans = 0;
	for (int i = 1; i <= k; i++)
	{
		memset(cnt, 0, sizeof cnt);
		for (int j = a[i].h; j <= a[i].a; j++)
		{
			if (cnt[j - a[i].h] < a[i].c && f[j - a[i].h] && !f[j])
			{
				f[j] = true;
				cnt[j] = cnt[j - a[i].h] + 1;
				ans = max(ans, j);
			}
		}
	}
	cout << ans;
}
