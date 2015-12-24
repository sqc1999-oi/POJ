#include <iostream>
#include <algorithm>

using namespace std;
int f[30001], d[30001];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i];
	int res = 0;
	for (int i = 1; i <= 2; i++)
	{
		f[1] = d[1];
		int len = 1;
		for (int i = 2; i <= n; i++)
		{
			if (d[i] >= f[len]) f[++len] = d[i];
			else *upper_bound(f + 1, f + 1 + len, d[i]) = d[i];
		}
		res = max(res, len);
		if (i == 1) reverse(d + 1, d + 1 + n);
	}
	cout << n - res << endl;
}
