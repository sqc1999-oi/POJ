#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t[100001], ans[100001];
struct seg
{
	int s, e, id;
	bool operator <(const seg &b) const
	{
		return e > b.e || (e == b.e&&s < b.s);
	}
	bool operator ==(const seg &b) const
	{
		return s == b.s&&e == b.e;
	}
} a[100001];
inline int lowbit(int x)
{
	return x & -x;
}

void Add(int pos, int val)
{
	while (pos <= 100000)
	{
		t[pos] += val;
		pos += lowbit(pos);
	}
}

int Query(int pos)
{
	int ans = 0;
	while (pos > 0)
	{
		ans += t[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n&&n != 0)
	{
		memset(t, 0, sizeof t);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].s >> a[i].e;
			a[i].s++;
			a[i].e++;
			a[i].id = i;
		}
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++)
		{
			int cnt = 0;
			for (int j = i - 1; j > 0 && a[i] == a[j]; j--) cnt++;
			ans[a[i].id] = Query(a[i].s) - cnt;
			Add(a[i].s, 1);
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << endl;
	}
}