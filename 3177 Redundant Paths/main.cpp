#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;
const int N = 5e3;
vector<int> g[N];
set<pair<int, int> > s;
void tarjan(int u, int fa)
{
	static int ts[N], low[N], time = 1;
	static bool ins[N];
	static stack<int> s;
	if (ts[u] != 0) return;
	ts[u] = low[u] = time++;
	s.push(u);
	ins[u] = true;
	bool flag = false;
	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (ts[v] == 0)
		{
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= ts[v])
			{
				::s.insert(make_pair(u, v));
				::s.insert(make_pair(v, u));
				while (s.top() != u)
				{
					ins[s.top()] = false;
					s.pop();
				}
			}
		}
		else if (ins[v] && (flag || v != fa)) low[u] = min(low[u], ts[v]);
		if (v == fa) flag = true;
	}
}
int dfs(int u, int fa)
{
	static bool vis[N];
	if (vis[u]) return 0;
	vis[u] = true;
	int cnt = 0;
	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (s.find(make_pair(u, v)) != s.end()) cnt++;
		else if (!vis[v] && v != fa) cnt += dfs(v, u);
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) tarjan(i, -1);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (dfs(i, -1) == 1) cnt++;
	cout << (cnt + 1) / 2 << endl;
}
