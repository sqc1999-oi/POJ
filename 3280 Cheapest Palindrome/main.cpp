#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char s[2000];
int cost[26], f[2000][2000];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		char ch;
		int a, b;
		cin >> ch >> a >> b;
		cost[ch - 'a'] = min(a, b);
	}
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
			else f[i][j] = min(f[i + 1][j] + cost[s[i] - 'a'], f[i][j - 1] + cost[s[j] - 'a']);
		}
	}
	cout << f[0][m - 1];
}
