#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[11], tmp[11][11];
int main()
{
	ios::sync_with_stdio(false);
	int n, sum;
	cin >> n >> sum;
	for (int i = 1; i <= n; i++) a[i] = i;
	do
	{
		memcpy(tmp[1], a, sizeof a);
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= n - i + 1; j++)
			{
				tmp[i][j] = tmp[i - 1][j] + tmp[i - 1][j + 1];
			}
		}
		if (tmp[n][1] == sum)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << a[i] << ' ';
			}
			return 0;
		}
	}
	while (next_permutation(a + 1, a + 1 + n));
}
