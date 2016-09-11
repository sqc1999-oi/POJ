#include <iostream>
#include <algorithm>
using namespace std;

struct
{
	int f1, f2, l;
	char d;
} a[40001];

struct q
{
	int f1, f2, l, id;

	bool operator<(const q& a) const
	{
		return l < a.l;
	}
} b[40001];

int p[40001], ans[40001];
pair<int, int> d[40001];

int find(int x)
{
	if (x == p[x]) return x;
	int t = p[x];
	p[x] = find(p[x]);
	d[x].first += d[t].first;
	d[x].second += d[t].second;
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i].f1 >> a[i].f2 >> a[i].l >> a[i].d;
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) cin >> b[i].f1 >> b[i].f2 >> b[i].l , b[i].id = i;
	sort(b + 1, b + 1 + k);
	for (int i = 1; i <= n; i++) p[i] = i;
	int j = 1;
	for (int i = 1; i <= k; i++)
	{
		for (; j <= b[i].l; j++)
		{
			int f1 = find(a[j].f1), f2 = find(a[j].f2);
			if (f1 != f2)
			{
				p[f2] = f1;
				int x = 0, y = 0;
				switch (a[j].d)
				{
				case 'N':
					y = a[j].l;
					break;
				case 'S':
					y = -a[j].l;
					break;
				case 'W':
					x = -a[j].l;
					break;
				case 'E':
					x = a[j].l;
					break;
				}
				d[f2].first = d[a[j].f1].first - d[a[j].f2].first - x;
				d[f2].second = d[a[j].f1].second - d[a[j].f2].second - y;
			}
		}
		if (find(b[i].f1) != find(b[i].f2)) ans[b[i].id] = -1;
		else ans[b[i].id] = abs(d[b[i].f1].first - d[b[i].f2].first) + abs(d[b[i].f1].second - d[b[i].f2].second);
	}
	for (int i = 1; i <= k; i++) cout << ans[i] << endl;
}
