#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 370;
struct
{
	int x, y;
} que[N*N], dir[8];
int num[N][N], dp[N][N], n, tf, f, l;
bool ok(int x, int y, int i, int j)
{
	if (x >= 1 && x <= n&&y >= 1 && y <= n)
	{
		if (num[x][y]>num[i][j])
			return true;
	}
	return false;
}
void dfs(int i, int j) 
{
	int tx, ty;
	if (dp[i][j] != -1) return;
	dp[i][j] = 1;
	for (int k = 0; k<8; k++) 
	{
		tx = i + dir[k].x;
		ty = j + dir[k].y;
		if (ok(tx, ty, i, j)) 
		{
			dfs(tx, ty);
			if (dp[i][j] == -1 || dp[tx][ty] + 1>dp[i][j])
				dp[i][j] = dp[tx][ty] + 1;
		}
	}
}
int main()
{
	dir[0].x = 2, dir[0].y = 1; dir[1].x = 2, dir[1].y = -1;
	dir[2].x = -2, dir[2].y = 1; dir[3].x = -2, dir[3].y = -1;
	dir[4].x = 1, dir[4].y = 2; dir[5].x = -1; dir[5].y = 2;
	dir[6].x = 1, dir[6].y = -2; dir[7].x = -1, dir[7].y = -2;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &num[i][j]);
				dp[i][j] = -1;
			}
		}
		f = l = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dp[i][j] == -1)
				{
					dfs(i, j);
					if (f == l)
					{
						que[l].x = i, que[l].y = j;
						l++;
					}
					else if (dp[i][j] > dp[que[l - 1].x][que[l - 1].y] || (dp[i][j] == dp[que[l - 1].x][que[l - 1].y] && num[i][j] < num[que[l - 1].x][que[l - 1].y]))
					{
						l = f;
						que[l].x = i, que[l].y = j;
						l++;
					}
					else if (dp[i][j] == dp[que[l - 1].x][que[l - 1].y] && num[i][j] == num[que[l - 1].x][que[l - 1].y])
					{
						que[l].x = i, que[l].y = j;
						l++;
					}
				}
			}
		}
		printf("%d\n", dp[que[f].x][que[f].y]);
		tf = f; f = l;
		int tx, ty, x, y;
		while (tf<f)
		{
			if (f == l)
			{
				printf("%d\n", num[que[tf].x][que[tf].y]);
			}
			x = que[tf].x; y = que[tf].y;
			for (int i = 0; i <= 8; i++)
			{
				tx = x + dir[i].x;
				ty = y + dir[i].y;
				if (ok(tx, ty, x, y))
				{
					if (dp[tx][ty] + 1 == dp[x][y])
					{
						if (f == l) {
							que[l].x = tx, que[l].y = ty;
							l++;
						}
						else if (dp[tx][ty]>dp[que[l - 1].x][que[l - 1].y] || (dp[tx][ty] == dp[que[l - 1].x][que[l - 1].y] && num[tx][ty] < num[que[l - 1].x][que[l - 1].y]))
						{
							l = f;
							que[l].x = tx, que[l].y = ty;
							l++;
						}
						else if (dp[tx][ty] == dp[que[l - 1].x][que[l - 1].y] && num[tx][ty] == num[que[l - 1].x][que[l - 1].y])
						{
							que[l].x = tx, que[l].y = ty;
							l++;
						}
					}
				}
			}
			tf++;
			if (tf == f)
			{
				tf = f; f = l;
			}
		}
	}
	return 0;
}