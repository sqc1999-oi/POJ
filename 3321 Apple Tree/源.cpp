#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
	int To, Next;
} E[200001];

int index, dfn[100001], l[100001], r[100001], n, t[100001], cnt;
bool HasApple[100001];
int G[100001];

void dfs(int u, int fa)
{
	l[u] = r[u] = dfn[u] = ++index;
	for (int i = G[u]; i != 0; i = E[i].Next)
	{
		if (E[i].To != fa)
		{
			dfs(E[i].To, u);
			l[u] = min(l[u], l[E[i].To]);
			r[u] = max(r[u], r[E[i].To]);
		}
	}
}

inline int lowbit(int x)
{
	return x & -x;
}

void Add(int pos, int val)
{
	while (pos <= n)
	{
		t[pos] += val;
		pos += lowbit(pos);
	}
}

int Query(int pos)
{
	int ans = 0;
	while (pos > 0)
	{
		ans += t[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

void AddEdge(int from, int to)
{
	E[++cnt] = Edge{ to,G[from] };
	G[from] = cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		AddEdge(a, b);
		AddEdge(b, a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		Add(i, 1);
		HasApple[i] = true;
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		char ch;
		int pos;
		cin >> ch >> pos;
		if (ch == 'Q') cout << Query(r[pos]) - Query(l[pos] - 1) << endl;
		else if (ch == 'C')
		{
			if (HasApple[pos]) Add(dfn[pos], -1);
			else Add(dfn[pos], 1);
			HasApple[pos] ^= 1;
		}
	}
}