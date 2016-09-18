#include<iostream>
#include<algorithm>
using namespace std;
int r[1001];
int main()
{
	ios::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> r[i];
	}
	for (int i = 1; i <= t; i++)
	{
		int a = 1, b = r[1];
		for (int j = 2; j <= n; j++)
		{
			if (r[j] > r[a]) b = r[j], a = j;
		}
		r[a] = 0;
		cout << a << endl;
		if (i == t) break;
		for (int j = 1; j <= n; j++)
		{
			if (j != a)
			{
				r[j] += b / (n - 1);
			}
		}
		for (int j = 1; j <= b % (n - 1); j++)
		{
			if (j == a) r[b % (n - 1) + 1]++;
			else r[j]++;
		}
	}
}
