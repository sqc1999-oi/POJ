#include <iostream>
#include <algorithm>
using namespace std;
long long a[500001], tmp[500001];

long long solve(int l, int r)
{
	long long ans = 0;
	if (l < r)
	{
		int mid = (l + r) / 2;
		ans += solve(l, mid);
		ans += solve(mid + 1, r);
		int i = l, j = mid + 1, k = l;
		while (i <= mid && j <= r)
		{
			if (a[i] > a[j])
			{
				tmp[k++] = a[j++];
				ans += mid - i + 1;
			}
			else tmp[k++] = a[i++];
		}
		while (i <= mid) tmp[k++] = a[i++];
		while (j <= r) tmp[k++] = a[j++];
		for (int i = l; i <= r; i++) a[i] = tmp[i];
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n != 0)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		cout << solve(1, n) << endl;
	}
}
