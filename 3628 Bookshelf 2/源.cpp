#include<iostream>
#include<algorithm>
using namespace std;
int a[21];
int ans = 0x7fffffff;
void dfs(int n, int ex)
{
	if (n == 0)
	{
		if (ex >= 0) ans = min(ans, ex);
	}
	else
	{
		dfs(n - 1, ex);
		dfs(n - 1, ex + a[n]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, b;
	cin >> n >> b;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(n, -b);
	cout << ans << endl;
}