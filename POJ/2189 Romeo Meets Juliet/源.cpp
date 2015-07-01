#include<iostream>
#include<algorithm>
using namespace std;
int a[1001];
int main()
{
	ios::sync_with_stdio(false);
	int n, p, c;
	cin >> n >> p >> c;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	int ans = 0;
	for (int i = 1; i < p; i++)
	{
		int j = i, cnt = a[i];
		while (j < p&&cnt <= c) j++, cnt += a[j];
		ans = max(ans, j - i);
	}
	cout << ans << endl;
}