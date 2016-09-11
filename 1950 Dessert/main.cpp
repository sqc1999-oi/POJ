#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt = 0;
char a[17];
void dfs(int x)
{
	if (x > n)
	{
		int sum = 0, tmp = 0;
		char last;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == '.')
			{
				(tmp *= (i < 10 ? 10 : 100)) += i;
				if (a[i + 1] != '.') sum += tmp*(last == '+' ? 1 : -1);
			}
			else
			{
				last = a[i];
				tmp = i;
				if (a[i + 1] != '.') sum += i*(a[i] == '+' ? 1 : -1);
			}
		}
		if (sum == 0)
		{
			cnt++;
			if (cnt <= 20)
			{
				cout << 1 << ' ';
				for (int i = 2; i <= n; i++) cout << a[i] << ' ' << i << ' ';
				cout << endl;
			}
		}
		return;
	}
	a[x] = '+';
	dfs(x + 1);
	a[x] = '-';
	dfs(x + 1);
	a[x] = '.';
	dfs(x + 1);
	a[x] = 0;
}
int main()
{
	a[0] = '_';
	ios::sync_with_stdio(false);
	cin >> n;
	a[1] = '+';
	dfs(2);
	cout << cnt << endl;
}
