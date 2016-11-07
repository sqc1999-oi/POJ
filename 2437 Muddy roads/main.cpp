#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct mud
{
	int s, e;
	bool operator<(const mud &a) const
	{
		return s < a.s;
	}
} a[10001];
int main()
{
	ios::sync_with_stdio(false);
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].s >> a[i].e;
	}
	sort(a + 1, a + 1 + n);
	int pos = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pos>=a[i].e) continue;
		else if (pos >= a[i].s) a[i].s = pos;
		else pos = a[i].s;
		int x = (int)ceil((double)(a[i].e - a[i].s) / l);
		pos += x*l;
		cnt += x;
	}
	cout << cnt;
}
