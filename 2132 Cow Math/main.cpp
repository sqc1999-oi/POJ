#include<iostream>
#include<algorithm>
using namespace std;
int n, map[26][26];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a%b); }
long long lcm(long long a, long long b) { return a*b / gcd(a, b); }
long long ans = 1;
bool vis[26];
void dfs(int x, int g)
{
	if (x == 2)
	{
		ans = lcm(ans, g);
		return;
	}
	if (ans%g == 0) return;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && map[x][i])
		{
			vis[i] = true;
			dfs(i, gcd(g, map[x][i]));
			vis[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (map[1][i])
		{
			vis[i] = true;
			dfs(i, map[1][i]);
			vis[i] = false;
		}
	}
	cout << ans << endl;
}
