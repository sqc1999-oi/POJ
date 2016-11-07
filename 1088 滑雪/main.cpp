#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct point
{
	int x, y;
};
int n, m, a[101][101], dis[101][101], ma = 0;
point p[10001];
bool operator <(const point& i, const point &j)
{
	return a[i.x][i.y]>a[j.x][j.y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int k = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		cin >> a[i][j];
		k++;
		p[k].x = i;
		p[k].y = j;
	}
	sort(p + 1, p + 1 + n*m);
	for (int i = 1; i <= n*m; i++)
	{
		int u, d, l, r;
		u = d = l = r = 1;
		if (p[i].x + 1 <= n&&a[p[i].x + 1][p[i].y]>a[p[i].x][p[i].y]) d = dis[p[i].x + 1][p[i].y] + 1;
		if (p[i].x - 1>0 && a[p[i].x - 1][p[i].y]>a[p[i].x][p[i].y]) u = dis[p[i].x - 1][p[i].y] + 1;
		if (p[i].y + 1 <= m&&a[p[i].x][p[i].y + 1]>a[p[i].x][p[i].y]) r = dis[p[i].x][p[i].y + 1] + 1;
		if (p[i].y - 1>0 && a[p[i].x][p[i].y - 1]>a[p[i].x][p[i].y]) l = dis[p[i].x][p[i].y - 1] + 1;
		dis[p[i].x][p[i].y] = max(max(u, d), max(l, r));
		ma = max(ma, dis[p[i].x][p[i].y]);
	}
	cout << ma;
	return 0;
}
