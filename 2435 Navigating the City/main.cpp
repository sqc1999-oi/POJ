#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 100 + 10, INF = 1 << 30;

struct po 
{
	int x, y;
	po(int a = 0, int b = 0) { x = a, y = b; }
};

char s[MAXN][MAXN];
int dic[MAXN][MAXN][10];
int d[10][10] = { { 0, 0 },{ 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };
char four[10] = { ' ', 'E', 'W', 'S', 'N' };
pair <int, int> fa[MAXN][MAXN];
int vis[MAXN][MAXN] = { 0 };
int sx, sy, ex, ey;

vector <char> path;

int dfs(int x, int y)
{
	if (x == -1 && y == -1) return 0;
	dfs(fa[x][y].first, fa[x][y].second);
	for (int i = 1; i <= 4; i++) 
	{
		if (fa[x][y].first + d[i][0] == x && fa[x][y].second + d[i][1] == y)
		{
			if (s[x][y] == '-' || s[x][y] == '|') path.push_back(four[i]);
			return 0;
		}
	}
}
int n, m;
int bfs()
{
	queue<po> q;
	path.clear();
	q.push(po(sx, sy));
	memset(vis, 0, sizeof(vis));
	fa[sx][sy].first = -1;
	fa[sx][sy].second = -1;
	while (!q.empty())
	{
		po p = q.front();
		q.pop();
		vis[p.x][p.y] = 1;
		if (p.x == ex && p.y == ey) 
		{
			dfs(ex, ey);
			return 1;
		}
		for (int i = 1; i <= 4; i++)
		{
			int xx = p.x + d[i][0], yy = p.y + d[i][1];
			if (xx < 1 || xx > 2 * n - 1 || yy < 1 || yy > 2 * m - 1|| dic[xx][yy][0] || vis[xx][yy]) continue;
			if (dic[p.x][p.y][i]) 
			{
				q.push(po(xx, yy));
				vis[xx][yy] = 1;
				fa[xx][yy].first = p.x;
				fa[xx][yy].second = p.y;
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int j = 1; j <= 2 * m - 1; j++)
		{
			cin >> s[i][j];
		}
	}
	memset(dic, 0, sizeof(dic));
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int j = 1; j <= 2 * m - 1; j++)
		{
			if (s[i][j] == '.') dic[i][j][0] = 1;
			else if (s[i][j] == '-') dic[i][j][1] = dic[i][j][2] = 1;
			else if (s[i][j] == '+') dic[i][j][1] = dic[i][j][2] = dic[i][j][3] = dic[i][j][4] = 1;
			else if (s[i][j] == '|') dic[i][j][3] = dic[i][j][4] = 1;
			else if (s[i][j] == 'S') sx = i, sy = j;
			else if (s[i][j] == 'E') ex = i, ey = j;
		}
	}
	dic[sx][sy][1] = dic[sx][sy][2] = dic[sx][sy][3] = dic[sx][sy][4] = 1;
	bfs();
	int len = path.size();
	int ans = 1;
	for (int i = 1; i < len; i++) 
	{
		if (path[i] != path[i - 1]) 
		{
			cout << path[i - 1] << ' ' << ans << endl;
			ans = 1;
		}
		else ans++;
	}
	cout << path[len - 1] << ' ' << ans;
	return 0;
}
