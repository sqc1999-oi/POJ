#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int X[] = {1, 0, 0, -1};
const int Y[] = {0, 1, -1, 0};
char map[1001][1001];
int ans, px, py, n, m;

void dfs(int x, int y, int fx, int fy, int d)
{
	if (d > ans)
	{
		ans = d;
		px = x;
		py = y;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + X[i], ny = y + Y[i];
		if (nx > 0 && nx <= n && ny > 0 && ny <= m && !(nx == fx && ny == fy) && map[nx][ny] == '.')
		{
			dfs(nx, ny, x, y, d + 1);
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d\n", &m, &n);
		int sx, sy;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				map[i][j] = getchar();
				if (map[i][j] == '.') sx = i , sy = j;
			}
			getchar();
		}
		ans = 0;
		dfs(sx, sy, 0, 0, 0);
		ans = 0;
		dfs(px, py, 0, 0, 0);
		printf("Maximum rope length is %d.\n", ans);
	}
}
