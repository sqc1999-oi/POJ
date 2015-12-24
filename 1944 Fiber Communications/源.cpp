#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> ps[10001];
int main()
{
	ios::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	for (int i = 1; i <= p; i++)
	{
		cin >> ps[i].first >> ps[i].second;
		if (ps[i].first > ps[i].second) swap(ps[i].first, ps[i].second);
	}
	int ans = 0x7fffffff;
	for (int i = 1; i <= n; i++)
	{
		int l1 = 0x7fffffff, r1 = 0, l2 = 0x7fffffff, r2 = 0;
		for (int j = 1; j <= p; j++)
		{
			if (ps[j].first <= i&&ps[j].second > i)
			{
				l1 = min(l1, 1);
				r1 = max(r1, ps[j].first);
				l2 = min(l2, ps[j].second);
				r2 = max(r2, n + 1);
			}
			else if (ps[j].second <= i)
			{
				l1 = min(l1, ps[j].first);
				r1 = max(r1, ps[j].second);
			}
			else if (ps[j].first > i)
			{
				l2 = min(l2, ps[j].first);
				r2 = max(r2, ps[j].second);
			}
		}
		ans = min(ans, (l1 < r1 ? r1 - l1 : 0) + (l2 < r2 ? r2 - l2 : 0));
	}
	cout << ans << endl;
}
