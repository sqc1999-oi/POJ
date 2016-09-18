#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t[1001][1001], n;

inline int lowbit(int x)
{
	return x & -x;
}

void Add(int x, int y)
{
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j))
			t[i][j]++;
}

int Query(int x, int y)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			ans += t[i][j];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int x;
	cin >> x;
	while (x--)
	{
		int q;
		cin >> n >> q;
		memset(t, 0x00, sizeof t);
		for (int i = 1; i <= q; i++)
		{
			char ch;
			cin >> ch;
			if (ch == 'C')
			{
				int x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				Add(x2 + 1, y2 + 1);
				Add(x1, y1);
				Add(x1, y2 + 1);
				Add(x2 + 1, y1);
			}
			else if (ch == 'Q')
			{
				int x, y;
				cin >> x >> y;
				cout << Query(x, y) % 2 << endl;
			}
		}
		cout << endl;
	}
}
