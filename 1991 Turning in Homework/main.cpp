#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
pii a[1001];
int f[1001][1001][2];

int main()
{
	ios::sync_with_stdio(false);
	int c, h, b;
	cin >> c >> h >> b;
	for (int i = 1; i <= c; i++) cin >> a[i].first >> a[i].second;
	sort(a + 1, a + 1 + c);
	f[1][c][0] = max(a[1].first, a[1].second);
	f[1][c][1] = max(a[c].first, a[c].second);
	for (int i = c - 2; i >= 0; i--)
	{
		for (int s = 1; s + i <= c; s++)
		{
			int e = s + i;
			f[s][e][0] = 0x7fffffff;
			if (s > 1) f[s][e][0] = min(f[s][e][0], f[s - 1][e][0] + a[s].first - a[s - 1].first);
			if (e < c) f[s][e][0] = min(f[s][e][0], f[s][e + 1][1] + a[e + 1].first - a[s].first);
			f[s][e][0] = max(f[s][e][0], a[s].second);
			f[s][e][1] = 0x7fffffff;
			if (e < c) f[s][e][1] = min(f[s][e][1], f[s][e + 1][1] + a[e + 1].first - a[e].first);
			if (s > 1) f[s][e][1] = min(f[s][e][1], f[s - 1][e][0] + a[e].first - a[s - 1].first);
			f[s][e][1] = max(f[s][e][1], a[e].second);
		}
	}
	int ans = 0x7fffffff;
	for (int i = 1; i <= c; i++) ans = min(ans, min(f[i][i][0], f[i][i][1]) + abs(a[i].first - b));
	cout << ans;
}
