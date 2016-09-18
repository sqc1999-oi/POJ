#include <cstdio>
#define sqr(a) (a)*(a)
#define max(a, b) (a) > (b) ? (a) : (b);
char map[101][101];
int p[100001][2];
int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			char ch;
			do ch = getchar();
			while (ch != 'J'&&ch != 'B'&&ch != '*');
			if (ch == 'B') map[j][n - i + 1] = -1;
			else if (ch == 'J')
			{
				map[j][n - i + 1] = 1;
				p[++cnt][0] = j;
				p[cnt][1] = n - i + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		int x1 = p[i][0], y1 = p[i][1];
		for (int j = i + 1; j <= cnt; ++j)
		{
			int x2 = p[j][0], y2 = p[j][1];
			float mx = (x1 + x2) / 2.0f, my = (y1 + y2) / 2.0f;
			float tmp;
			tmp = mx + (y1 - y2) / 2.0f;
			int x3 = (int)tmp;
			if (tmp != x3 || x3 > n || x3 < 1) continue;
			tmp = my + (x2 - x1) / 2.0f;
			int y3 = (int)tmp;
			if (tmp != y3 || y3 > n || y3 < 1 || map[x3][y3] == -1) continue;
			int x4 = (int)(mx - (y1 - y2) / 2.0f);
			if (x4 > n || x4 < 1) continue;
			int y4 = (int)(my - (x2 - x1) / 2.0f);
			if (y4 > n || y4 < 1 || map[x4][y4] == -1) continue;
			if (map[x3][y3] == 1 || map[x4][y4] == 1) ans = max(ans, sqr(x3 - x1) + sqr(y3 - y1));
		}
	}
	printf("%d", ans);
}
