#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef int arr[20000];
arr s, sa, x, y, r, h;
int c[1000001];
bool equ(int *x, int i, int j, int k, int n)
{
	if (x[i] != x[j]) return false;
	if (i + k >= n && j + k >= n) return true;
	if (i + k < n && j + k < n && x[i + k] == x[j + k]) return true;
	return false;
}
bool check(int mid, int n, int k)
{
	int cnt = 1;
	for (int i = 1; i < n; i++)
		if (h[i] >= mid)
		{ if (++cnt == k) return true; }
		else cnt = 1;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	int *x = ::x, *y = ::y, m = 1000001;
	for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
	for (int i = 1; i < m; i++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
	for (int j = 1; j <= n; j *= 2)
	{
		int p = 0;
		for (int i = n - j; i < n; i++) y[p++] = i;
		for (int i = 0; i < n; i++)
			if (sa[i] >= j) y[p++] = sa[i] - j;
		memset(c, 0x00, sizeof c);
		for (int i = 0; i < n; i++) c[x[i]]++;
		for (int i = 1; i < m; i++) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		x[sa[0]] = 0;
		p = 1;
		for (int i = 1; i < n; i++)
			x[sa[i]] = equ(y, sa[i], sa[i - 1], j, n) ? p - 1 : p++;
		if (p >= n) break;
		m = p;
	}
	for (int i = 0; i < n; i++) r[sa[i]] = i;
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		if (r[i] == 0) continue;
		if (len) len--;
		int j = sa[r[i] - 1];
		while (i + len < n && j + len < n && s[i + len] == s[j + len]) len++;
		h[r[i]] = len;
	}
	int L = 0, R = n, ans;
	while (L <= R)
	{
		int mid = (L + R) / 2;
		if (check(mid, n, k))
		{
			ans = mid;
			L = mid + 1;
		}
		else R = mid - 1;
	}
	cout << ans;
}
