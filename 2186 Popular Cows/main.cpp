#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
vector<int> g[10001], ng[10001];
stack<int> s;
int map[10001], cnt[10001], low[10001], dfn[10001], index = 0;
bool vis[10001], ins[10001];
void tarjan(int u)
{
	low[u] = dfn[u] = ++index;
	vis[u] = true;
	s.push(u);
	ins[u] = true;
	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (!vis[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (ins[v])
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u])
	{
		int v;
		do
		{
			v = s.top();
			s.pop();
			ins[v] = false;
			map[v] = u;
			cnt[u]++;
		} while (u != v);
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
		g[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) map[i] = i;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			if (map[i]!=map[g[i][j]])
			ng[map[i]].push_back(map[g[i][j]]);
		}
	}
	bool found = false;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (map[i] == i&&ng[i].size() == 0)
		{
			if (!found)
			{
				found = true;
				ans = cnt[i];
			}
			else
			{
				ans = 0;
				break;
			}
		}
	}
	cout << ans << endl;
}
