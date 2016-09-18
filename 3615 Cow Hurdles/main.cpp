#include <string.h>
#include <stdio.h>

#define max(a, b) (a)>(b)?(a):(b)
#define min(a, b) (a)<(b)?(a):(b)
int map[301][301];

int main()
{
	memset(map, 0x3f, sizeof(map));
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= m; i++)
	{
		int s, e, h;
		scanf("%d%d%d", &s, &e, &h);
		map[s][e] = h;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = min(map[i][j], max(map[i][k], map[k][j]));
			}
		}
	}
	for (int i = 1; i <= t; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", map[a][b] == 0x3f3f3f3f ? -1 : map[a][b]);
	}
}
