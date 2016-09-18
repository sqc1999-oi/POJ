#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[41];
bool f[801][801];
int main()
{
	ios::sync_with_stdio(false);
	int n, c = 0;
	double x, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], c += a[i];
	x = c / 2.0;
	f[0][0] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = x - 1; j >= 0; j--)
		{
			for (int k = j; k >= 0; k--)
			{
				if (a[i] <= j) f[j][k] |= f[j - a[i]][k];
				if (a[i] <= k) f[j][k] |= f[j][k - a[i]];
				if (f[j][k]) ans = max(ans, x*(x - j)*(x - k)*(x - c + j + k));
			}
		}
	}
	cout << ((ans > 0 ? (int)(sqrt(ans) * 100) : -1));
}
