#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct cow
{
	int v, x;

	bool operator <(const cow& b) const
	{
		return x < b.x;
	}
} a[20001];

long long cnt[20001], dis[20001];
int m;

inline int lowbit(int x)
{
	return x & -x;
}

void add(int val, int pos, long long* arr)
{
	while (pos <= m)
	{
		arr[pos] += val;
		pos += lowbit(pos);
	}
}

long long query(int pos, long long* arr)
{
	long long ans = 0;
	while (pos > 0)
	{
		ans += arr[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

long long solve(int n, bool flag)
{
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		long long c = query(a[i].v - flag, cnt), d = query(a[i].v - flag, dis);
		ans += llabs(c * a[i].x - d) * a[i].v;
		add(1, a[i].v, cnt);
		add(a[i].x, a[i].v, dis);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].v >> a[i].x;
		m = max(m, a[i].v);
	}
	sort(a + 1, a + 1 + n);
	long long ans = solve(n, true);
	reverse(a + 1, a + 1 + n);
	memset(cnt, 0, sizeof cnt);
	memset(dis, 0, sizeof dis);
	ans += solve(n, false);
	cout << ans;
}
