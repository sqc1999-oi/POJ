#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int p[10001], pmin[10001], pmax[10001], f[110000];
const int INF = 0x7fffffff;
int main()
{
	ios::sync_with_stdio(false);
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> p[i];
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	int d = l/(n - 1);
	fill(f, f + l + 1, INF);
	f[0] = p[1];
	pmin[1] = 0;
	pmax[1] = 0;
	pmin[n] = l;
	pmax[n] = l;
	for (int i = 2; i < n; i++)
	{
		pmin[i] = d*(i - 1);
		pmax[i] = min((d + 1)*(i - 1), l);
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = pmax[i]; j >= pmin[i]; j--)
		{
			f[j] = INF;
			if (j - d <= pmax[i - 1] && j - d >= pmin[i - 1]) f[j] = min(f[j], f[j - d] + abs(j - p[i]));
			if (j - d - 1 <= pmax[i - 1] && j - d - 1 >= pmin[i - 1])f[j] = min(f[j], f[j - d - 1] + abs(j - p[i]));
		}
	}
	cout << f[l] << endl;
}