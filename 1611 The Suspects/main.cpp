#include <iostream>
#include <algorithm>
using namespace std;
int p[30501];

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n + m; i++)
			p[i] = i;
		for (int i = 1; i <= m; i++)
		{
			int k;
			cin >> k;
			for (int j = 1; j <= k; j++)
			{
				int x;
				cin >> x;
				p[find(x)] = find(i + n - 1);
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (find(0) == find(i)) cnt++;
		cout << cnt << endl;
	}
}
