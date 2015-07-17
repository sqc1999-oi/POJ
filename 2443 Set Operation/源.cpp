#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;
bitset<1001> s[10001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int j = 1; j <= x; j++)
		{
			int xx;
			scanf("%d", &xx);
			s[xx][i] = 1;
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		bool flag = false;
		for (int j = 1; j <= n; j++)
		{
			if (s[a][j] == 1 && s[b][j] == 1)
			{
				puts("Yes");
				flag = true;
				break;
			}
		}
		if (!flag) puts("No");
	}
}