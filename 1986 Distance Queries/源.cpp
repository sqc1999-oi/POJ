#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Edge
{
	int From, To, Pow, Next;

	Edge(int from, int to, int pow, int next) :From(from), To(to), Pow(pow), Next(next) {}

	Edge() {}
};

int G[40001];
Edge E[80000];
int b[80000], pos[40001], index, rmq[80000][17], cnt;

inline void AddEdge(int from, int to, int pow)
{
	E[++cnt] = Edge(from, to, pow, G[from]);
	G[from] = cnt;
}

void dfs(int u, int fa, int d)
{
	b[++index] = d;
	pos[u] = index;
	for (int i = G[u]; i != 0; i = E[i].Next)
	{
		if (E[i].To != fa)
		{
			dfs(E[i].To, u, d + E[i].Pow);
			b[++index] = d;
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
		AddEdge(f1, f2, l);
		AddEdge(f2, f1, l);
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
		int xx = min(rmq[x][l], rmq[y - (1 << l) + 1][l]);
		cout << b[x] - xx + b[y] - xx << endl;
	}
}