#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
pair<int, int> a[10001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
	int l, p;
	cin >> l >> p;
	for (int i = 1; i <= n; i++) a[i].first = l - a[i].first;
	sort(a + 1, a + 1 + n);
	a[n + 1].first = l;
	a[n + 1].second = 0;
	priority_queue<int> q;
	int cnt = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		while (a[i].first - a[i - 1].first > p)
		{
			if (q.empty())
			{
				cout << -1 << endl;
				return 0;
			}
			p += q.top();
			q.pop();
			cnt++;
		}
		p -= a[i].first - a[i - 1].first;
		q.push(a[i].second);
	}
	cout << cnt << endl;
}