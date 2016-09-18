#include <iostream>
#include <algorithm>
using namespace std;
int f[2001], a[2001], b[2001];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		int m = 0x3f3f3f3f;
		for (int j = 1; j <= n; j++)
		{
			m = min(m, f[j]);
			f[j] = m + abs(a[i] - b[j]);
		}
	}
	cout << *min_element(f + 1, f + 1 + n);
}
