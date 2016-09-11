#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	stack<long long> s;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;
		while (!s.empty() && s.top() <= x) s.pop();
		ans += s.size();
		s.push(x);
	}
	cout << ans;
}
