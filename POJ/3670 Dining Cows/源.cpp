#include<iostream>
#include<algorithm>
using namespace std;
int sum1[30001], sum2[30001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int d;
		cin >> d;
		sum2[i] = sum2[i - 1] + d - 1;
	}
	for (int i = 1; i <= n; i++)
	{
		sum1[i] = n - i + 1 - (sum2[n] - sum2[i - 1]);
	}
	int ans = min(sum1[1], sum2[n]);
	for (int i = 1; i < n; i++)
	{
		ans = min(ans, sum2[i] + sum1[i + 1]);
	}
	cout << ans << endl;
}