#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
	int From, To, Pow;
};

vector<Edge> G[40001];
int x, md;

void dfs(int u, int fa, int d)
{
	if (d > md) md = d , x = u;
	for (int i = 0; i < G[u].size(); i++)
	{
		Edge& e = G[u][i];
		if (e.To != fa)
		{
			dfs(e.To, e.From, d + e.Pow);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int f1, f2, l;
		char d;
		cin >> f1 >> f2 >> l >> d;
		G[f1].push_back(Edge{f1,f2,l});
		G[f2].push_back(Edge{f2,f1,l});
	}
	dfs(1, 0, 0);
	dfs(x, 0, 0);
	cout << md;
}
