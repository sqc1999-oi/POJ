#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int sum[100001], n, f;
const double eps = 1e-10;
bool check(double val)
{
	double tmp = sum[f - 1] - val*(f - 1);
	for (int i = f; i <= n; i++)
	{
		tmp += sum[i] - sum[i - 1] - val;
		tmp = max(tmp, sum[i] - sum[i - f] - val*f);
		if (tmp > -eps) return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	double l = 2000, r = 0;
	cin >> n >> f;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		l = min(l, (double)x);
		r = max(r, (double)x);
		sum[i] = sum[i - 1] + x;
	}
	while (fabs(l - r) >= eps)
	{
		double mid = (l + r) / 2.0;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << (int)(r * 1000);
}
