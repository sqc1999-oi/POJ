#include<iostream>
#include<cmath>
using namespace std;
const double eps = 1e-8;
const double A[] = { 1.0,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10 };
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		double p = m*A[n], q = (m + 1)*A[n];
		double x = 0, y = 0;
		while (x == y)
		{
			p++;
			q++;
			x = floor(p*p);
			y = floor(q*q - eps);
		}
		cout << (int)floor(y) << endl;
	}
}
