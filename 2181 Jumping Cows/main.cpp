#include <iostream>
#include <algorithm>
using namespace std;
int f[150001][2];
int main()
{
	ios::sync_with_stdio(false);
	int p;
	cin >> p;
	for (int i = 1; i <= p; i++)
	{
		int x;
		cin >> x;
		f[i][0] = max(f[i - 1][0], f[i - 1][1] - x);
		f[i][1] = max(f[i - 1][1], f[i - 1][0] + x);
	}
	cout << max(f[p][0], f[p][1]);
}
