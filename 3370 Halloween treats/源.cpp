#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int s[100001], vis[100001];

int main()
{
	int c, n;
	while (scanf("%d%d", &c, &n) != EOF && !(c == 0 && n == 0))
	{
		s[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &s[i]);
			(s[i] += s[i - 1]) %= c;
		}
		memset(vis, 0x00, sizeof vis);
		int l = 0, r = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == 0)
			{
				l = 1;
				r = i;
				break;
			}
			if (vis[s[i]])
			{
				l = vis[s[i]] + 1;
				r = i;
				break;
			}
			vis[s[i]] = i;
		}
		if (l > r) return 0;
		for (int i = l; i <= r; i++) printf("%d ", i);
		puts("");
	}
}