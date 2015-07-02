#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct cow
{
	int start, stop, machine;
	bool operator<(const cow &a) const
	{
		return stop > a.stop;
	}
} a[50001];
int r[50001];
bool cmp(const int &x, const int &y)
{
	return a[x].start < a[y].start;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].start >> a[i].stop;
	}
	for (int i = 1; i <= n; i++) r[i] = i;
	sort(r + 1, r + 1 + n, cmp);
	priority_queue<cow> q;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!q.empty() && q.top().stop < a[r[i]].start)
		{
			a[r[i]].machine = q.top().machine;
			q.pop();
		}
		else a[r[i]].machine = q.size() + 1;
		q.push(a[r[i]]);
		ans = max(ans, (int)q.size());
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) cout << a[i].machine << endl;
}