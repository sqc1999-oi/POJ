#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[10001], f[10001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	long long ans = 0;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] + (i - 1)*(a[i] - a[i - 1]);
		ans += f[i];
	}
	cout << ans * 2;
}
