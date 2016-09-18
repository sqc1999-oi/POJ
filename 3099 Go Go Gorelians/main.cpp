#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> G[1001];

struct planet
{
	int id, x, y, z;
} a[1001];

int getdis(const planet& a, const planet& b)
{
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2);
}

int ans, pos;

void dfs(int u, int fa, int d)
{
	if (d > ans)
	{
		ans = d;
		pos = u;
	}
	for (int i = 0; i < (int)G[u].size(); i++) if (G[u][i] != fa) dfs(G[u][i], u, d + 1);
}

int ans1, ans2;

int dfs2(int u, int fa)
{
	int res = 0;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		if (G[u][i] != fa)
		{
			int x = dfs2(G[u][i], u) + 1;
			res = max(res, x);
		}
	}
	if (ans / 2 == res) ans1 = u;
	else if (ans % 2 == 1 && ans / 2 + 1 == res) ans2 = u;
	return res;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		for (int i = 1; i <= 1000; i++) G[i].clear();
		int x;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].id >> a[i].x >> a[i].y >> a[i].z;
			x = a[i].id;
			int d = 1e10, p = 0;
			for (int j = 1; j < i; j++)
			{
				int x = getdis(a[i], a[j]);
				if (x < d)
				{
					d = x;
					p = j;
				}
			}
			if (p != 0)
			{
				G[a[i].id].push_back(a[p].id);
				G[a[p].id].push_back(a[i].id);
			}
		}
		ans = 0;
		dfs(x, 0, 0);
		ans = 0;
		dfs(pos, 0, 0);
		dfs2(pos, 0);
		if (ans % 2 == 0) cout << ans1 << endl;
		else
		{
			if (ans1 > ans2) swap(ans1, ans2);
			cout << ans1 << ' ' << ans2 << endl;
		}
	}
}
