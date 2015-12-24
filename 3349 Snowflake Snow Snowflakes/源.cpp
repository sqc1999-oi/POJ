#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int a[100001][6];
const int M = 14997;
vector<int> h[M];

bool compare(const int& x, const int& y)
{
	for (int i = 0; i < 6; i++)
	{
		if (a[x][i] == a[y][0])
		{
			int j = (i + 1) % 6, k = 1;
			while (j != i && a[x][j] == a[y][k])
				++j %= 6 , ++k;
			if (j == i) return true;
			j = (i + 5) % 6;
			k = 1;
			while (j != i && a[x][j] == a[y][k])
				(--j += 6) %= 6 , ++k;
			if (j == i) return true;
		}
	}
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 0; j < 6; j++) scanf("%d", &a[i][j]), (sum += a[i][j]) %= M;
		h[sum].push_back(i);
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < h[i].size(); j++)
		{
			for (int k = j + 1; k < h[i].size(); k++)
			{
				if (compare(h[i][j], h[i][k]))
				{
					puts("Twin snowflakes found.");
					return 0;
				}
			}
		}
	}
	puts("No two snowflakes are alike.");
}
