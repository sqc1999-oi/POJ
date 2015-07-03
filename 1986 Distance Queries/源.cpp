#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Edge
{
	int From, To, Pow;
};

vector<Edge> G[40001];
int f[80000], b[80000], pos[40001], index, rmq[80000][18];

void dfs(int u, int fa, int d)
{
	f[++index] = u;
	b[index] = d;
	pos[u] = index;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i].To != fa)
		{
			dfs(G[u][i].To, u, d + G[u][i].Pow);
			f[++index] = u;
			b[index] = d;
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
		G[f1].push_back(Edge{ f1,f2,l });
		G[f2].push_back(Edge{ f2,f1,l });
	}
	dfs(1, 0, 0);
	int log = int(log2(2 * n - 1));
	for (int i = 1; i <= 2 * n - 1; i++) rmq[i][0] = b[i];
	for (int i = 1; i <= log; i++)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (j + (1 << i) > 2 * n) break;
			rmq[j][i] = min(rmq[j][i - 1], rmq[j + (1 << i - 1)][i - 1]);
		}
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		x = pos[x];
		y = pos[y];
		if (x > y) swap(x, y);
		int l = int(log2(y - x));
		int k = min(rmq[x][l], rmq[y - (1 << l) + 1][l]);
		cout << b[x] - k + b[y] - k << endl;
	}
}