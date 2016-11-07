#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
const double EPS = 1e-8;
int main()
{
	ios::sync_with_stdio(false);
	double L, n, C;
	while (cin >> L >> n >> C && L != -1)
	{
		double nL = (1 + n * C) * L, l = 0, r = L / 2;
		while (fabs(l - r) > EPS)
		{
			double mid = (l + r) / 2;
			double radius = mid / 2 + L * L / 8 / mid;
			double x = radius * (asin(L / 2 / radius) * 2);
			if (x > nL)
				r = mid;
			else
				l = mid;
		}
		cout << fixed << setprecision(3) << l << endl;
	}
}
