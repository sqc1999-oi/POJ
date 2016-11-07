#include <iostream>
#include <algorithm>

using namespace std;

struct Interval
{
	int start, end, eff;

	bool operator<(const Interval a) const { return end < a.end; }
} a[1001];

int f[2000001];

int main()
{
	ios::sync_with_stdio(false);
	int n, m, r;
	cin >> n >> m >> r;
	n = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].start >> a[i].end >> a[i].eff;
		a[i].end += r;
		n = max(n, a[i].end);
	}
	sort(a + 1, a + 1 + m);
	if (m > 0) f[a[1].end] = a[1].eff;
	for (int i = 2; i <= m; i++)
	{
		int j = a[i - 1].end;
		for (; j + 1 < a[i].end; j++) f[j + 1] = f[j];
		f[a[i].end] = max(f[a[i].end], f[j]);
		f[a[i].end] = max(f[a[i].end], f[a[i].start] + a[i].eff);
	}
	cout << f[n];
}
