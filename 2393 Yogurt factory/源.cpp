#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, s, m = 0x3f3f3f3f;
	long long ans = 0;
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		int c, y;
		cin >> c >> y;
		c = min(c, m + s);
		m = c;
		ans += c * y;
	}
	cout << ans;
}
