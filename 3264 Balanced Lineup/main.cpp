#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int Min[50001][16],Max[50001][16];
int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> Min[i][0], Max[i][0] = Min[i][0];
	int k = (int)log2(n + 0.5);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j + (1 << i) - 1 <= n; j++)
		{
			Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
			Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		int k = (int)log2(b - a + 1 + 0.5);
		cout << (max(Max[a][k], Max[b - (1 << k) + 1][k]) - min(Min[a][k], Min[b - (1 << k) + 1][k])) << endl;
	}
}
