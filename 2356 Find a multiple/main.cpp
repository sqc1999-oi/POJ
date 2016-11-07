#include <iostream>
#include <algorithm>
using namespace std;
int a[10001], vis[10001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0;
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		(sum += a[i]) %= n;
		if (sum == 0)
		{
			l = 1;
			r = i;
			break;
		}
		if (vis[sum])
		{
			l = vis[sum] + 1;
			r = i;
			break;
		}
		vis[sum] = i;
	}
	cout << r - l + 1 << endl;
	for (int i = l; i <= r; i++) cout << a[i] << endl;
}
