#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
	int To, Pow, Next;
} E[80000];

int G[40001], cnt, n, m, k;
bool vis[40001];

void AddEdge(int from, int to, int pow)
{
	E[++cnt] = Edge{ to,pow,G[from] };
	G[from] = cnt;
}

struct Focus
{
private:
	static int size, pos;

	static int calcSize(int u, int fa)
	{
		int tot = 1;
		for (int i = G[u]; i != 0; i = E[i].Next)
		{
			if (E[i].To != fa && !vis[E[i].To])
			{
				tot += calcSize(E[i].To, u);
			}
		}
		return tot;
	}

	static int dfs(int u, int fa, int s)
	{
		int m = 0, sum = 0;
		for (int i = G[u]; i != 0; i = E[i].Next)
		{
			if (E[i].To != fa && !vis[E[i].To])
			{
				int t = dfs(E[i].To, u, s);
				sum += t;
				m = max(m, t);
			}
		}
		m = max(m, s - sum - 1);
		if (m < size)
		{
			size = m;
			pos = u;
		}
		return sum + 1;
	}

public:
	static int GetFocus(int root)
	{
		size = 0x7fffffff;
		dfs(root, 0, calcSize(root, 0));
		return pos;
	}
};

struct Depth
{
	static int D[40001], Cnt;

	static void CalcDep(int u, int fa, int d)
	{
		D[++Cnt] = d;
		for (int i = G[u]; i != 0; i = E[i].Next)
		{
			if (E[i].To != fa && !vis[E[i].To])
			{
				CalcDep(E[i].To, u, d + E[i].Pow);
			}
		}
	}
};

int Ans = 0;
int Focus::size, Focus::pos, Depth::D[40001], Depth::Cnt;

int Calc(int u, int d)
{
	Depth::Cnt = 0;
	Depth::CalcDep(u, 0, d);
	sort(Depth::D + 1, Depth::D + 1 + Depth::Cnt);
	int pos = Depth::Cnt, ans = 0;
	for (int i = 1; i <= Depth::Cnt; i++)
	{
		while (Depth::D[i] + Depth::D[pos] > k && pos > i) pos--;
		if (pos == i) break;
		ans += pos - i;
	}
	return ans;
}

void Solve(int u)
{
	vis[u] = true;
	Ans += Calc(u, 0);
	for (int i = G[u]; i != 0; i = E[i].Next)
	{
		if (!vis[E[i].To])
		{
			Ans -= Calc(E[i].To, E[i].Pow);
			Solve(Focus::GetFocus(E[i].To));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int f1, f2, l;
		char d;
		cin >> f1 >> f2 >> l >> d;
		AddEdge(f1, f2, l);
		AddEdge(f2, f1, l);
	}
	cin >> k;
	Solve(Focus::GetFocus(1));
	cout << Ans;
}