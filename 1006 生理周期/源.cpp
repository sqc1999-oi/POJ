#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int p, e, i, d;
	int t = 0;
	while (cin >> p >> e >> i >> d&&!(p == -1 && e == -1 && i == -1 && d == -1))
	{
		int ans = ((5544 * p + 14421 * e + 1288 * i - d) % 21252 + 21252) % 21252;
		if (ans == 0) ans = 21252;
		cout << "Case " << ++t << ": the next triple peak occurs in " << ans << " days." << endl;
	}
}
