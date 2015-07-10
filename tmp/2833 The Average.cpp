#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q1;
priority_queue<int> q2;
int main()
{
	int n1, n2, n;
	while (~scanf("%d%d%d", &n1, &n2, &n))
	{
		if (n1 == 0 && n2 == 0 && n == 0) break;
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			ans += x;
			if (q1.size() < n1) q1.push(x);
			else if (x > q1.top()) q1.pop(), q1.push(x);
			if (q2.size() < n2) q2.push(x);
			else if (x < q2.top()) q2.pop(), q2.push(x);
		}
		while (!q1.empty())
			ans -= q1.top(), q1.pop();
		while (!q2.empty())
			ans -= q2.top(), q2.pop();
		printf("%.6f\n", (double) ans / (n - n1 - n2));
	}
}
