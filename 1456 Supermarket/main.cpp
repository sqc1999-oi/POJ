#include <iostream>
#include <algorithm>
using namespace std;

struct product
{
	int p, d;

	bool operator <(const product &b) const
	{
		return p > b.p;
	}
} a[10001];

int p[10001];

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		int m = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].p >> a[i].d;
			m = max(m, a[i].d);
		}
		for (int i = 0; i <= m; i++)
			p[i] = i;
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = find(a[i].d);
			if (x > 0)
			{
				ans += a[i].p;
				p[x] = find(x - 1);
			}
		}
		cout << ans << endl;
	}
}
