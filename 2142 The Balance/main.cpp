#include <iostream>
#include <algorithm>
using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int tmp = exgcd(b, a % b, y, x);
	y -= x * (a / b);
	return tmp;
}

void solve(int a, int b, int d, int x, int &sum, int &nx, int &ny, bool flag)
{
	x *= d;
	x = (x % b + b) % b;
	int y = (d - a * x) / b;
	y = abs(y);
	if (x + y < sum)
	{
		nx = x;
		ny = y;
		sum = x + y;
		if (flag) swap(nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int a, b, d;
	while (cin >> a >> b >> d && !(a == 0 && b == 0 && d == 0))
	{
		int x, y;
		int g = exgcd(a, b, x, y);
		a /= g;
		b /= g;
		d /= g;
		int sum = 0x7fffffff;
		int nx, ny;
		solve(a, b, d, x, sum, nx, ny, false);
		solve(b, a, d, y, sum, nx, ny, true);
		cout << nx << ' ' << ny << endl;
	}
}
