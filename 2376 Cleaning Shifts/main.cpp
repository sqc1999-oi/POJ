#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
pii cow[25001];
int main()
{
	ios::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> cow[i].first >> cow[i].second;
	sort(cow + 1, cow + 1 + n);
	if (cow[1].first > 1)
	{
		cout << -1;
		return 0;
	}
	int s = 1, e = 1, cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		if (cow[i].first <= s) e = max(e, cow[i].second);
		else
		{
			cnt++;
			s = e + 1;
			if (cow[i].first > s)
			{
				cout << -1;
				return 0;
			}
			e = max(e, cow[i].second);
		}
		if (e >= t) break;
	}
	if (e >= t) cout << cnt;
	else cout << -1;
}
