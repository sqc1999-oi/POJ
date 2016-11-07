#include<iostream>
#include<algorithm>
using namespace std;
int a[1001], f[1001][31];
int main()
{
	ios::sync_with_stdio(false);
	int t, w;
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= t; i++) f[i][0] = f[i - 1][0] + a[i] % 2;

	for (int i = 1; i <= w; i++)
	{
		for (int j = i; j <= t; j++)
		{
			f[j][i] = max(f[j - 1][i], f[j - 1][i - 1]);
			f[j][i] += i % 2 + 1 == a[j];
		}
	}
	cout << *max_element(f[t], f[t] + 1 + w);
}
