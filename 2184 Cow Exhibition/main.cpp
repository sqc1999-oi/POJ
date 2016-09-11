#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 0x7fffffff - 10000;
const int OFFSET = 100000;
int s[101], f[101], dp[100001 + OFFSET];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i] >> f[i];
	fill(dp, dp + 100001 + OFFSET, -INF);
	dp[0 + OFFSET] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] > 0) for (int j = 100000 + OFFSET; j >= s[i]; j--) dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
		else for (int j = 0; j - OFFSET - s[i] <= 100000; j++) dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
	}
	int ans = 0;
	for (int i = 0 + OFFSET; i <= 100000 + OFFSET; i++)
	{
		if (dp[i] >= 0) ans = max(ans, dp[i] + i - OFFSET);
	}
	cout << ans << endl;
}
