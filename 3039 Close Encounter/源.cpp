#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a%b); }
struct fraction
{
	long long numerator, denominator;
	fraction(long long n, long long d)
	{
		long long x = gcd(n, d);
		numerator = n / x;
		denominator = d / x;
	}
	bool operator<(fraction f) 
	{
		return numerator*f.denominator < f.numerator*denominator;
	}
	bool operator==(fraction f) 
	{
		return numerator*f.denominator == f.numerator*denominator;
	}
	bool operator!=(fraction f) 
	{
		return !(f == *this);
	}
	fraction operator-(fraction f)
	{
		return fraction(numerator*f.denominator - f.numerator*denominator, denominator*f.denominator);
	}
	fraction operator-() 
	{
		return fraction(-numerator, denominator);
	}
};
fraction Abs(fraction f) 
{
	return f.numerator*f.denominator < 0 ? -f : f; 
}
int main()
{
	ios::sync_with_stdio(false);
	int n, d;
	cin >> n >> d;
	fraction f(n, d), ans(1, 1);
	for (int i = 1; i <= 32767; i++)
	{
		if (i == 32764)
		{
			i = 32764;
		}
		long long x = f.numerator*i / f.denominator, y = i;
		fraction tmp(x, y);
		if (tmp.numerator != 0 && tmp != f && Abs(tmp - f) < Abs(ans - f)) ans = tmp;
		if (x < y - 1)
		{
			tmp = fraction(x + 1, y);
			if (tmp != f && Abs(tmp - f) < Abs(ans - f)) ans = tmp;
		}
	}
	cout << ans.numerator << ' ' << ans.denominator;
}