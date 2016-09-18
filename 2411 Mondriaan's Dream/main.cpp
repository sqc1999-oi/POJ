#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long f[12][3000], n, m;

string to_string(int x)
{
	string ans;
	do
	{
		ans += x % 2 + '0';
		x /= 2;
	}
	while (x != 0);
	while (ans.length() < m) ans += '0';
	return ans;
}

bool test_first(int s)
{
	for (int i = 1; i <= m; i++)
	{
		if (s & 1 << i - 1)
		{
			if (i == m || !(s & 1 << i)) return false;;
			i++;
		}
	}
	return true;
}

bool test(int s1, int s2)
{
	for (int i = 1; i <= m; i++)
	{
		if (!(s1 & 1 << i - 1))
		{
			if (!(s2 & 1 << i - 1)) return false;
		}
		else
		{
			if (s2 & 1 << i - 1)
			{
				if (i == m || !(s1 & 1 << i && s2 & 1 << i)) return false;
				i++;
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m && !(n == 0 && m == 0))
	{
		if (m > n) swap(n, m);
		memset(f, 0, sizeof f);
		for (int i = 0; i < 1 << m; i++) if (test_first(i)) f[1][i]++;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < 1 << m; j++)
			{
				for (int k = 0; k < 1 << m; k++)
				{
					if (test(j, k))
					{
						f[i][j] += f[i - 1][k];
					}
				}
			}
		}
		cout << f[n][(1 << m) - 1] << endl;
	}
}
