#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
	int To, Pow;
};

vector<Edge> G[100001];
int ans, pos;

void dfs(int u, int fa, int d)
{
	if (d > ans)
	{
		ans = d;
		pos = u;
	}
	for (int i = 0; i < G[u].size(); i++) if (G[u][i].To != fa) dfs(G[u][i].To, u, d + G[u][i].Pow);
}

int main()
{
	ios::sync_with_stdio(false);
	int n, s, sum = 0;
	cin >> n >> s;
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back(Edge{b, c});
		G[b].push_back(Edge{a, c});
		sum += 2 * c;
	}
	dfs(1, 0, 0);
	ans = 0;
	dfs(pos, 0, 0);
	cout << sum - ans << endl;
}
