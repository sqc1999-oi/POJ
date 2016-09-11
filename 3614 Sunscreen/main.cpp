#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct cow
{
	int min, max;
	bool operator <(const cow &b) const { return min < b.min; }
} a[2501];
struct sunscreen
{
	int spf, cover;
	bool operator <(const sunscreen &b) const { return spf < b.spf; }
} b[2501];
struct cmp
{
	bool operator ()(const cow &a, const cow &b) { return a.max > b.max; }
};
int main()
{
	ios::sync_with_stdio(false);
	int c, l;
	cin >> c >> l;
	for (int i = 1; i <= c; i++) cin >> a[i].min >> a[i].max;
	for (int i = 1; i <= l; i++) cin >> b[i].spf >> b[i].cover;
	sort(a + 1, a + 1 + c);
	sort(b + 1, b + 1 + l);
	priority_queue<cow, vector<cow>, cmp> q;
	int ans = 0;
	for (int i = 1, j = 1; i <= l; i++)
	{
		while (j <= c&&a[j].min <= b[i].spf)
		{
			q.push(a[j]);
			j++;
		}
		while (!q.empty() && b[i].cover > 0)
		{
			cow x = q.top();
			q.pop();
			if (x.max >= b[i].spf)
			{
				b[i].cover--;
				ans++;
			}
		}
	}
	cout << ans << endl;
}
