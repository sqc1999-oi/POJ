#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

struct
{
	int a, b, s;
} a[5001];

int p[10001], d[10001];
int map[10001];

int find(int x)
{
	if (x == p[x]) return x;
	int t = find(p[x]);
	(d[x] += d[p[x]]) %= 2;
	return p[x] = t;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		memset(d, 0, sizeof d);
		for (int i = 1; i <= m; i++)
		{
			cin >> a[i].a >> a[i].b;
			string s;
			cin >> s;
			a[i].s = s == "odd";
			map[i] = a[i].a;
			map[i + m] = a[i].b;
		}
		sort(map + 1, map + 1 + 2 * m);
		int *end = unique(map + 1, map + 1 + 2 * m);
		for (int i = 0; i <= end - map - 1; i++)
			p[i] = i;
		int ans = m;
		for (int i = 1; i <= m; i++)
		{
			int x = lower_bound(map + 1, end, a[i].a) - map, y = lower_bound(map + 1, end, a[i].b) - map;
			x--;
			int xx = find(x), yy = find(y);
			if (xx == yy && (d[x] + d[y]) % 2 != a[i].s)
			{
				ans = i - 1;
				break;
			}
			if (xx != yy)
			{
				p[xx] = yy;
				d[xx] = ((d[y] + a[i].s) % 2 + d[x]) % 2;
			}
		}
		cout << ans << endl;
	}
}
