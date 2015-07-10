#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
char map[41][41];
const int D[][2] = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
const int X[] = { 3, 0, 1, 2 };
int dfs(int x, int y, int d, int n, int m, int tx, int ty)
{
	for (int i = d, j = 1; j <= 4; (++i) %= 4)
	{
		int nx = x + D[i][0], ny = y + D[i][1];
		if (nx == tx && ny == ty) return 2;
		if (nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny] != '#') return dfs(nx, ny, X[i], n, m, tx, ty) + 1;
	}
	return 0;
}
int dis[41][41];
int bfs(int sx, int sy, int n, int m)
{
	memset(dis, 255, sizeof dis);
	dis[sx][sy] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(sx, sy));
	while (!q.empty())
	{
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> v = make_pair(u.first + D[i][0], u.second + D[i][1]);
			if (v.first > 0 && v.first <= n && v.second > 0 && v.second <= m && dis[v.first][v.second] == -1 && map[v.first][v.second] != '#')
			{
				dis[v.first][v.second] = dis[u.first][u.second] + 1;
				if (map[v.first][v.second] == 'E') return dis[v.first][v.second];
				q.push(v);
			}
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--)
	{
		int w, h;
		cin >> w >> h;
		int sx, sy, tx, ty;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S') sx = i, sy = j;
				else if (map[i][j] == 'E') tx = i, ty = j;
			}
		}
		cout << dfs(sx, sy, 0, h, w, tx, ty) << ' ' << dfs(tx, ty, 0, h, w, sx, sy) << ' ' << bfs(sx, sy, h, w) << endl;
	}
}
