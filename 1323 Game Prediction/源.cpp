#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool a[1001];
int main()
{
	ios::sync_with_stdio(false);
	int m, n, t = 0;
	while (cin >> m >> n&&n != 0 && m != 0)
	{
		memset(a, 0, sizeof a);
		t++;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			a[x] = true;
		}
		int ans = 0, cnt = 0;
		for (int i = n*m; i > 0; i--)
		{
			if (!a[i]) cnt++;
			else if (cnt == 0) ans++;
			else cnt--;
		}
		cout << "Case " << t << ": " << ans << endl;
	}
}