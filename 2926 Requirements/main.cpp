#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
double a[6], m[32];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	fill(m, m + 32, -1e100);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 5; j++) cin >> a[j];
		for (int j = 0; j < 32; j++)
		{
			double x = 0;
			for (int k = 1; k <= 5; k++)
			{
				if ((j&(1 << (k - 1)))>0) x += a[k];
				else x -= a[k];
			}
			m[j] = max(m[j], x);
		}
	}
	double ans = -1e100;
	for (int i = 0; i < 32; i++)
	{
		ans = max(ans, m[i] + m[31 - i]);
	}
	cout.setf(ios::fixed);
	cout << setprecision(2);
	cout << ans;
}
