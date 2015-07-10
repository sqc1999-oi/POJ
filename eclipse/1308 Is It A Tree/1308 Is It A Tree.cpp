#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int p[101];
bool vis[101];
int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	int cnt = 0;
	while (true)
	{
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= 100; i++)
			p[i] = i;
		bool flag = true;
		int a, b, xx;
		while (cin >> a >> b)
		{
			if (a <= 0 && b <= 0) break;
			if (!flag) continue;
			int x = find(a), y = find(b);
			if (x == y)
			{
				flag = false;
				continue;
			}
			p[x] = y;
			vis[a] = vis[b] = true;
			xx = a;
		}
		if (flag)
		{
			for (int i = 1; i <= 100; i++)
			{
				if (vis[i] && find(xx) != find(i))
				{
					flag = false;
					break;
				}
			}
		}
		if (a == -1 && b == -1) break;
		cout << "Case " << ++cnt << " is" << (flag ? "" : " not") << " a tree." << endl;
	}
}
