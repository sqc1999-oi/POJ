#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, w, cnt = 0;
	cin >> n >> w;
	stack<int> s;
	s.push(0);
	for (int i = 1; i <= n + 1; i++)
	{
		int x, y;
		cin >> x >> y;
		if (i == n + 1) y = 0;
		while (y < s.top())
		{
			cnt++;
			s.pop();
		}
		if (y > s.top()) s.push(y);
	}
	cout << cnt << endl;
}
