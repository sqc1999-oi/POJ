#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int f[1000001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			f[i] = f[i - 1];
		}
		else
		{
			(f[i] += f[i - 2]) %= 1000000000;
			(f[i] += f[i / 2]) %= 1000000000;
		}
	}
	cout << f[n];
}
