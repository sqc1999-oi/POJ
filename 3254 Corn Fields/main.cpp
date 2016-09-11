#include <iostream>
using namespace std;
bool map[13][13];
int f[13][5000], n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 1 << n; i++)
	{
		bool able = true;
		for (int j = 1; j <= n; j++)
		{
			if (!map[1][j] && (i & 1 << (j - 1)))
			{
				able = false;
				break;
			}
			if (j > 1 && ((i & 1 << (j - 1)) && (i & 1 << (j - 2))))
			{
				able = false;
				break;
			}
		}
		if (able) f[1][i] = 1;
	}
	for (int i = 2; i <= m; i++)
	{
		for (int j = 0; j < 1 << n; j++)
		{
			for (int k = 0; k < 1 << n; k++)
			{
				bool able = true;
				for (int l = 1; l <= n; l++)
				{
					if (!map[i][l] && (k & 1 << (l - 1)))
					{
						able = false;
						break;
					}
					if ((j & 1 << (l - 1)) && (k & 1 << (l - 1)))
					{
						able = false;
						break;
					}
					if (l > 1 && ((k & 1 << (l - 1)) && (k & 1 << (l - 2))))
					{
						able = false;
						break;
					}
				}
				if (able)
				{
					(f[i][k] += f[i - 1][j]) %= 100000000;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 1 << n; i++) (ans += f[m][i]) %= 100000000;
	cout << ans;
}
