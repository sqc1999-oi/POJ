#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct roller
{
	int x, w, f, c;
	bool operator<(const roller &a) const
	{
		return x + w < a.x + a.w;
	}
} a[10001];
int f[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	memset(f, 255, sizeof f);
	int l, n, b;
	cin >> l >> n >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].w >> a[i].f >> a[i].c;
	}
	sort(a + 1, a + 1 + n);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = b - a[i].c; j >= 0; j--)
		{
			if (f[a[i].x][j] != -1) f[a[i].x + a[i].w][j + a[i].c] = max(f[a[i].x + a[i].w][j + a[i].c], f[a[i].x][j] + a[i].f);
		}
	}
	cout << *max_element(f[l], f[l] + b + 1);
	
}
