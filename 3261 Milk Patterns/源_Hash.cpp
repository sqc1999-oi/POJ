#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const unsigned long long X = 123ull;
int a[20000];
unsigned long long h[20001], p[20001];
bool check(int mid, int n, int k)
{
	vector<int> v;
	for (int i = 0; i <= n - mid; i++)
		v.push_back(h[i] - h[i + mid] * p[mid]);
	sort(v.begin(), v.end());
	int cnt = 1;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1])
		{ if (++cnt >= k) return true; }
		else cnt = 1;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	h[n] = 0;
	for (int i = n - 1; i >= 0; i--)
		h[i] = h[i + 1] * X + a[i];
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * X;
	int l = 0, r = n, ans;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid, n, k))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}
