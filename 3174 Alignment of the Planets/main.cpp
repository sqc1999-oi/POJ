#include<iostream>
#include<algorithm>
using namespace std;
int x[800], y[800], a[100000000], b[100000000], c[100000000];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				if ((x[j] - x[i])*(y[k] - y[j]) == (x[k] - x[j])*(y[j] - y[i]))
				{
					cnt++;
					a[cnt] = i;
					b[cnt] = j;
					c[cnt] = k;
				}
			}
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++)
	{
		cout << a[i] << ' ' << b[i] << ' ' << c[i] << endl;
	}
}
