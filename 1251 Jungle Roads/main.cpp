#include <iostream>
#include <algorithm>
using namespace std;

struct edge
{
	int u, v, w;

	bool operator <(const edge &b) const
	{
		return w < b.w;
	}
} e[76];

int p[26];

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
		if (n == 0) break;
		for (int i = 1; i < n; i++)
		{
			char a;
			int k;
			cin >> a >> k;
			for (int j = 1; j <= k; j++)
			{
				char b;
				int c;
				cin >> b >> c;
				m++;
				e[m].u = a - 'A';
				e[m].v = b - 'A';
				e[m].w = c;
			}
		}
		for (int i = 0; i < n; i++)
			p[i] = i;
		sort(e + 1, e + 1 + m);
		int ans = 0;
		for (int i = 1; i <= m; i++)
		{
			int x = find(e[i].u), y = find(e[i].v);
			if (x != y)
			{
				p[x] = y;
				ans += e[i].w;
			}
		}
		cout << ans << endl;
	}
}
