#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		int s, t, r;
		cin >> s >> t >> r;
		int a = 0;
		double b = 0;
		while (true)
		{
			a += s*t;
			b += t;
			if (a >= n)
			{
				b -= (double)(a - n) / s;
				break;
			}
			b += r;
		}
		cout << (int)ceil(b) << endl;
	}
}
