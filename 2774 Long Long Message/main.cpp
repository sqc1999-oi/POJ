#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
typedef int arr[200002];
arr sa, x, y, r, h, c;
int trans(char x) { return x - 'a'; }
bool equ(int *x, int i, int j, int k, int n)
{
	if (x[i] != x[j]) return false;
	if (i + k >= n && j + k >= n) return true;
	if (i + k < n && j + k < n && x[i + k] == x[j + k]) return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	vector<int> s;
	s.resize(a.size() + 1 + b.size());
	transform(a.begin(), a.end(), s.begin(), trans);
	s[a.size()] = 26;
	transform(b.begin(), b.end(), s.begin() + a.size() + 1, trans);
	int *x = ::x, *y = ::y, n = s.size(), m = 27;
	for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
	for (int i = 1; i < m; i++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
	for (int k = 1; k <= n; k *= 2)
	{
		int p = 0;
		for (int i = n - k; i < n; i++) y[p++] = i;
		for (int i = 0; i < n; i++)
			if (sa[i] >= k) y[p++] = sa[i] - k;
		memset(c, 0x00, sizeof c);
		for (int i = 0; i < n; i++) c[x[i]]++;
		for (int i = 1; i < m; i++) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		x[sa[0]] = 0;
		p = 1;
		for (int i = 1; i < n; i++)
			x[sa[i]] = equ(y, sa[i], sa[i - 1], k, n) ? p - 1 : p++;
		if (p >= n) break;
		m = p;
	}
	for (int i = 0; i < n; i++) r[sa[i]] = i;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (r[i] == 0) continue;
		if (k) k--;
		int j = sa[r[i] - 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
		h[r[i]] = k;
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
		if ((sa[i] < a.length() && sa[i - 1] > a.length()) || (sa[i] > a.length() && sa[i - 1] < a.length()))
			ans = max(ans, h[i]);
	cout << ans;
}
