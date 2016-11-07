#include <iostream>
#include <algorithm>
using namespace std;
unsigned a[1001], n, c;
long long sum[1001], ans = 0;
void dfs(int x, long long tot)
{
	ans = max(ans, tot);
	if (x < 1 || tot + sum[x] < ans) return;
	dfs(x - 1, tot);
	if (tot + a[x] <= c) dfs(x - 1, tot + a[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
	dfs(n, 0);
	cout << ans << endl;
}
