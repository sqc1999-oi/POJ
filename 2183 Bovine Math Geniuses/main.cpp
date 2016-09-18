#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int t[1000000];
int main()
{
	ios::sync_with_stdio(false);
	int n, cnt = 1;
	cin >> n;
	t[n] = 1;
	while (true)
	{
		cnt++;
		int x = n % 100000 / 10;
		x *= x;
		x %= 1000000;
		if (t[x] > 0)
		{
			cout << x << ' ' << cnt - t[x] << ' ' << cnt - 1;
			return 0;
		}
		t[x] = cnt;
		n = x;
	}
}
