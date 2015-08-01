#include <iostream>
#include <algorithm>
using namespace std;
int flag[5001], tmp[5001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		if (ch == 'B')
		{
			flag[i] ^= 1;
			flag[i + 1] ^= 1;
		}
	}
	int ans, m = 0x7fffffff;
	for (int k = 1; k <= n; k++)
	{
		memcpy(tmp, flag, sizeof tmp);
		int cu = 0, cnt = 0;
		for (int i = 1; i <= n - k + 1; i++)
		{
			cu ^= tmp[i];
			if (cu)
			{
				tmp[i] ^= 1;
				tmp[i + k] ^= 1;
				cnt++;
				cu ^= 1;
			}
		}
		bool able = true;
		for (int i = n - k + 2; i <= n; i++)
		{
			cu ^= tmp[i];
			if (cu)
			{
				able = false;
				break;
			}
		}
		if (able)
		{
			if (cnt < m)
			{
				m = cnt;
				ans = k;
			}
			else if (cnt == m&&k < ans) ans = k;
		}
	}
	cout << ans << ' ' << m << endl;
}