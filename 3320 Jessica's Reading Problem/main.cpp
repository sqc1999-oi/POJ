#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> Map;
int a[1000001], Cnt[1000001];

int main()
{
	int n, tot = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (!Map[x]) Map[x] = ++tot;
		a[i] = Map[x];
	}
	int r = 1, cnt = 0, ans = 0x7fffffff;
	for (int l = 1; l <= n; l++)
	{
		while (r <= n && cnt < tot)
		{
			if (!Cnt[a[r]])
			{
				cnt++;
			}
			Cnt[a[r]]++;
			r++;
		}
		if (cnt == tot) ans = min(ans, r - l);
		Cnt[a[l]]--;
		if (!Cnt[a[l]]) cnt--;
	}
	printf("%d", ans);
}
