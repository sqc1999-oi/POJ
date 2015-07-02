#include <iostream>
#include <algorithm>

using namespace std;
int f[12881];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int w, d;
		cin >> w >> d;
		for (int j = m - w; j >= 0; j--)
		{
			f[j + w] = max(f[j + w], f[j] + d);
		}
	}
	cout << *max_element(f, f + m + 1);
}