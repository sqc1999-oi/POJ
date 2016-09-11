#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
int p[10001];

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		memset(p, 0, sizeof p);
		int n;
		cin >> n;
		for (int i = 1; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			p[b] = a;
		}
		stack<int> s1, s2;
		int a, b;
		cin >> a >> b;
		while (a != 0) s1.push(a) , a = p[a];
		while (b != 0) s2.push(b) , b = p[b];
		int ans;
		while (!s1.empty() && !s2.empty() && s1.top() == s2.top())
		{
			ans = s1.top();
			s1.pop();
			s2.pop();
		}
		cout << ans << endl;
	}
}
