#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<int> G[10001];
int ans = 0;
bool vis[10001];
int dfn[10001], low[10001];
int index;
stack<int> s;
void tarjan(int u)
{
	dfn[u] = low[u] = ++index;
	vis[u] = true;
	s.push(u);
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!vis[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u])
	{
		int v, cnt = 0;
		do
		{
			v = s.top();
			s.pop();
			cnt++;
		}
		while (u != v);
		if (cnt > 1) ans++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			tarjan(i);
		}
	}
	cout << ans;
}
