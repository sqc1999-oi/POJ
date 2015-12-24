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
	int k;
	while (cin >> k)
	{
		long long a1, r1;
		cin >> a1 >> r1;
		bool flag = true;
		for (int i = 2; i <= k; i++)
		{
			long long a2, r2;
			cin >> a2 >> r2;
			if (!flag) continue;
			long long x, y;
			long long g = exgcd(a1, a2, x, y);
			if ((r2 - r1) % g != 0)
			{
				flag = false;
				continue;
			}
			x *= (r2 - r1) / g;
			a2 /= g;
			x = (x % a2 + a2) % a2;
			r1 += x * a1;
			a1 *= a2;
		}
		if (!flag) cout << -1 << endl;
		else cout << r1 << endl;
	}
}
