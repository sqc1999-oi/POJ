#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
bool np[20001];
vector<int> p;
int main()
{
	ios::sync_with_stdio(false);
	for (int i = 2, _ = sqrt(20000.5); i <= _; i++)
	{
		if (!np[i])
		for (int j = i*i; j <= 20000; j += i)
		{
			np[j] = true;
		}
	}
	for (int i = 2; i <= 20000; i++)
	{
		if (!np[i]) p.push_back(i);
	}
	int n;
	while (cin >> n)
	{
		int ans, max = -1;
		for (int i = 1; i <= n; i++)
		{
			int x, tmp = 0;
			cin >> x;
			for (int j = 0; p[j] <= x; j++)
			{
				if (x%p[j] == 0) tmp = j;
			}
			if (tmp > max)
			{
				max = tmp;
				ans = x;
			}
		}
		cout << ans << endl;
	}
}
