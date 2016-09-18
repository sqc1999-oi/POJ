#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n != 0)
	{
		int m = sqrt(n + 0.5);
		int ans = n;
		for (int i = 2; i <= m; i++)
		{
			if (n % i == 0)
			{
				ans = ans / i * (i - 1);
				while (n % i == 0) n /= i;
			}
		}
		if (n > 1) ans = ans / n * (n - 1);
		cout << ans << endl;
	}
}
