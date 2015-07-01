#include<iostream>
#include<algorithm>
using namespace std;
int a[351][351], f[351][351];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) f[n][i] = a[n][i];
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			f[i][j] = a[i][j];
			f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
		}
	}
	cout << f[1][1] << endl;
}