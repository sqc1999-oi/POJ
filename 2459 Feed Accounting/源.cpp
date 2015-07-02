#include <iostream>
#include <algorithm>
using namespace std;
int a[2001];
int main()
{
	ios::sync_with_stdio(false);
	int c, f1, f2, d;
	cin >> c >> f1 >> f2 >> d;
	for (int i = 1; i <= c; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int i = x; i <= y; i++) a[i]++;
	}
	for (int i = d; i >= 0; i--)
	{
		f2 += a[i];
		if (f2 == f1)
		{
			cout << i;
			return 0;
		}
	}
}