#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int X[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
struct node { int x, y, found; };
int map[1001][1001], dis[1001][1001][2];
int main()
{
	int  w, h, sx, sy, tx, ty;
	scanf("%d%d", &w, &h);
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			getchar();
			map[i][j] = getchar() - '0';
			if (map[i][j] == 2) sx = i, sy = j;
		}
	}
	memset(dis, 255, sizeof dis);
	dis[sx][sy][0] = 0;
	queue<node> q;
	q.push(node{ sx,sy,0 });
	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			node x = { n.x + X[i][0],n.y + X[i][1],n.found };
			if (x.x > 0 && x.x <= h&&x.y > 0 && x.y <= w)
			{
				x.found = x.found || map[x.x][x.y] == 4;
				if (dis[x.x][x.y][x.found] == -1)
				{
					if (n.found&&map[x.x][x.y] != 1)
					{
						if (map[x.x][x.y] == 3)
						{
							printf("%d", dis[n.x][n.y][1] + 1);
							return 0;
						}
						q.push(x);
						dis[x.x][x.y][1] = dis[n.x][n.y][1] + 1;
					}
					else if (!n.found&&map[x.x][x.y] != 1 && map[x.x][x.y] != 3)
					{
						q.push(x);
						dis[x.x][x.y][x.found] = dis[n.x][n.y][n.found] + 1;
					}
				}
			}
		}
	}
}
