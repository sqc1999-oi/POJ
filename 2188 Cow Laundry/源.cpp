#include<iostream>
#include<algorithm>
using namespace std;
int a[1001], x[1001], y[1001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		x[i] = a;
		y[b] = i;
	}
	for (int i = 1; i <= n; i++) a[i] = y[x[i]];
	int cnt = 0;
	for (int i = 1; i <= n-1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j]) cnt++;
		}
	}
	cout << cnt << endl;
}
