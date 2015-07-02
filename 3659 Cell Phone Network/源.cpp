#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> G[10001];
int fa[10001], seq[10001], index = 0;
bool cov[10001], sel[10001];
void dfs(int x, int f)
{
	fa[x] = f;
	seq[++index] = x;
	for (int i = 0; i < G[x].size(); i++)
	{
		if (G[x][i] != f)
		{
			dfs(G[x][i], x);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = n; i > 0; i--)
	{
		if (!cov[seq[i]])
		{
			if (!sel[fa[seq[i]]])
			{
				sel[fa[seq[i]]] = true;
				ans++;
			}
			cov[seq[i]] = cov[fa[seq[i]]] = cov[fa[fa[seq[i]]]] = true;
		}
	}
	cout << ans;
}