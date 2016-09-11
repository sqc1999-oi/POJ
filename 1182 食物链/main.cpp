#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;
int p[150001];

inline int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}

inline void Union(int x, int y)
{
	int xx = Find(x), yy = Find(y);
	if (xx != yy) p[xx] = yy;
}

int main()
{
	int n, k, ans = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= 3 * n; i++)
		p[i] = i;
	for (int i = 1; i <= k; i++)
	{
		int a, x, y;
		scanf("%d%d%d", &a, &x, &y);
		if (x > n || y > n || x < 1 || y < 1)
		{
			ans++;
			continue;
		}
		if (a == 1)
		{
			if (Find(x + n) == Find(y) || Find(x + 2 * n) == Find(y))
			{
				ans++;
				continue;
			}
			Union(x, y);
			Union(x + n, y + n);
			Union(x + 2 * n, y + 2 * n);
		}
		else
		{
			if (Find(x) == Find(y) || Find(x + 2 * n) == Find(y))
			{
				ans++;
				continue;
			}
			Union(x, y + 2 * n);
			Union(x + n, y);
			Union(x + 2 * n, y + n);
		}
	}
	printf("%d", ans);
}
