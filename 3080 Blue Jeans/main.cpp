#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int Next[61];

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s[11];
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> s[i];
		int ans = 0;
		string res;
		for (int l = 0; l <= 57; l++)
		{
			Next[0] = Next[1];
			for (int i = 1, j = 0; i < s[1].length(); i++)
			{
				while (j > 0 && s[1][i] != s[1][j]) j = Next[j];
				if (s[1][i] == s[1][j]) j++;
				Next[i + 1] = j;
			}
			int m = 0x7fffffff;
			for (int k = 2; k <= n; k++)
			{
				int m1 = 0;
				for (int i = 0, j = 0; i < s[k].length(); i++)
				{
					while (j > 0 && s[k][i] != s[1][j]) j = Next[j];
					if (s[k][i] == s[1][j]) j++;
					m1 = max(m1, j);
					if (j == s[1].length()) j == Next[j];
				}
				m = min(m, m1);
			}
			if (m > ans) ans = m , res = s[1].substr(0, m);
			else if (m == ans && s[1].substr(0, m) < res) res = s[1].substr(0, m);
			s[1] = s[1].substr(1);
		}
		if (ans < 3) cout << "no significant commonalities" << endl;
		else cout << res << endl;
	}
}
