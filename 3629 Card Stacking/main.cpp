#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, k, p;
	cin >> n >> k >> p;
	queue<int> q;
	vector<int> ans;
	for (int i = 1; i <= k; i++) q.push(i);
	int cnt = 0;
	while (true)
	{
		if (++cnt == n)
		{
			cnt = 0;
			ans.push_back(q.front());
		}
		if (ans.size() == k / n) break;
		q.pop();
		for (int i = 1; i <= p; i++)
		{
			q.push(q.front());
			q.pop();
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}
