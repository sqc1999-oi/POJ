#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	double r;
	cin >> n >> r;
	double ans = acos(-1.0)*r * 2;
	double x0, y0, x1, y1;
	cin >> x0 >> y0;
	x1 = x0;
	y1 = y0;
	for (int i = 2; i <= n; i++)
	{
		double x, y;
		cin >> x >> y;
		ans += sqrt(pow(x - x1, 2) + pow(y - y1, 2));
		x1 = x;
		y1 = y;
	}
	ans += sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
	cout << fixed << setprecision(2) << ans << endl;
}
