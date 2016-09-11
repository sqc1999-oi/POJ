#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int d[100][100];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		memset(d, 0x3f, sizeof d);
		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			for (int j = 1; j <= k; j++)
			{
				int a, b;
				cin >> a >> b;
				d[i][a] = b;
			}
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		int ans = 0x7fffffff, pos;
		for (int i = 1; i <= n; i++)
		{
			int m = 0;
			for (int j = 1; j <= n; j++)
			{
				if (i != j)
				{
					m = max(m, d[i][j]);
				}
			}
			if (m < ans)
			{
				ans = m;
				pos = i;
			}
		}
		if (ans >= 0x3f3f3f3f) cout << "disjoint";
		else cout << pos << ' ' << ans << endl;
	}
}
