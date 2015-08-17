#include <iostream>
#include <algorithm>
using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long tmp = exgcd(b, a % b, y, x);
	y -= x * (a / b);
	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	long long x, y, m, n, l;
	cin >> x >> y >> m >> n >> l;
	if (n > m)
	{
		swap(n, m);
		swap(x, y);
	}
	long long X, Y;
	long long g = exgcd(m - n, l, X, Y);
	if ((y - x) % g != 0) cout << "Impossible" << endl;
	else
	{
		l /= g;
		cout << (((y - x) * X / g) % l + l) % l << endl;
	}
}