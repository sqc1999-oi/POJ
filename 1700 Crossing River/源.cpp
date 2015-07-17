#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int ans = 0;
		int i;
		for (i = n; i > 3; i -= 2)
		{
			ans += min(a[1] + a[2] * 2 + a[i], a[1] * 2 + a[i - 1] + a[i]);
		}
		if (i == 3) ans += a[1] + a[2] + a[3];
		else if (i == 2) ans += a[2];
		else ans += a[1];
		cout << ans << endl;
	}
}