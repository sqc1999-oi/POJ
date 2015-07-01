#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string s[1001];
vector<int> G[1001];
bool check(int a, int b)
{
	int sa = s[a].size(), sb = s[b].size();
	if (sa == sb - 1)
	{
		int i, j;
		i = j = 0;
		while (i < sa && j < sb)
		{
			if (s[a][i] != s[b][j])
			{
				j++;
				if (j - i > 1) return false;
			}
			else i++, j++;
		}
		return true;
	}
	else return false;
}
int ans = 0, pos = 0;
void dfs(int x, int d)
{
	if (d > ans)
	{
		ans = d;
		pos = x;
	}
	for (int i = 0; i < G[x].size(); i++)
	{
		dfs(G[x][i], d + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int d;
	cin >> d;
	for (int i = 0; i <= d; i++) cin >> s[i];
	for (int i = 0; i <= d; i++)
	{
		for (int j = 0; j <= d; j++)
		{
			if (check(i, j))
			{
				G[i].push_back(j);
			}
		}
	}
	dfs(0, 0);
	cout << s[pos];
}