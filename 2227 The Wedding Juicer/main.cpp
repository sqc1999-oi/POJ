#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
const int D[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int a[301][301], vis[301][301];
struct node
{
	int x, y, h;
	bool operator <(const node &b) const { return h>b.h; }
};
priority_queue<node> q;
int main()
{
	ios::sync_with_stdio(false);
	int w, h;
	cin >> w >> h;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
		{
			cin >> a[i][j];
			if (i == 1 || j == 1 || i == h || j == w)
			{
				q.push(node{ i,j,a[i][j] });
				vis[i][j] = true;
			}
		}
	long long ans = 0;
	while (!q.empty())
	{
		node u = q.top();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = u.x + D[i][0], y = u.y + D[i][1];
			if (x > 0 && x <= h&&y > 0 && y <= w&&!vis[x][y])
			{
				vis[x][y] = true;
				if (u.h > a[x][y])
				{
					ans += u.h - a[x][y];
					q.push(node{ x,y,u.h });
				}
				else q.push(node{ x,y,a[x][y] });
			}
		}
	}
	cout << ans << endl;
}
