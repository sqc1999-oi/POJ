#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<long long, vector<long long>, greater<long long>> q;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	long long ans = 0;
	while (q.size() > 1)
	{
		long long x = q.top();
		q.pop();
		long long y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	cout << ans;
}
