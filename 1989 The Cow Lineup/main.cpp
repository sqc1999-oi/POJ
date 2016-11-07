#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool vis[10001];
int main()
{
	ios::sync_with_stdio(false);
	int n, k, cnt = 0, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (!vis[x]) vis[x] = true, cnt++;
		if (cnt == k)
		{
			memset(vis, 0, sizeof vis);
			ans++;
			cnt = 0;
		}
	}
	cout << ans + 1;
}
