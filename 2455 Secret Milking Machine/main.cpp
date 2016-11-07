#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge
{
	int From, To, Pow, Cap, Flow, Next;
} E[80001];

struct e
{
	int From, To, Pow;

	bool operator <(const e& b) const
	{
		return Pow < b.Pow;
	}
} Edges[40001];

const int INF = 0x7fffffff;
int G[201], a[201], p[201], M, q[70000];

void AddEdge(int from, int to, int pow, int cap)
{
	E[++M] = Edge{from, to, pow, cap, 0, G[from]};
	G[from] = M;
	E[++M] = Edge{to, from, pow, cap, 0, G[to]};
	G[to] = M;
}

bool EK(int s, int t, int pow_limit, int flow_limit, int m)
{
	int flow = 0;
	memset(G, 255, sizeof G);
	M = -1;
	for (int i = 1; i <= m; i++)
	{
		if (Edges[i].Pow <= pow_limit) AddEdge(Edges[i].From, Edges[i].To, Edges[i].Pow, 1);
		else break;
	}
	while (true)
	{
		memset(a, 0, sizeof a);
		int h = 0, r = 0;
		q[r++] = s;
		a[s] = INF;
		while (h < r)
		{
			int u = q[h++];
			for (int i = G[u]; i != -1; i = E[i].Next)
			{
				if (!a[E[i].To] && E[i].Cap > E[i].Flow)
				{
					p[E[i].To] = i;
					a[E[i].To] = min(a[u], E[i].Cap - E[i].Flow);
					q[r++] = E[i].To;
				}
			}
			if (a[t]) break;
		}
		if (!a[t]) return false;
		for (int i = t; i != s; i = E[p[i]].From)
		{
			E[p[i]].Flow += a[t];
			E[p[i] ^ 1].Flow -= a[t];
		}
		flow += a[t];
		if (flow >= flow_limit) return true;
	}
}

int main()
{
	int n, p, t, l = INF, r = 0;
	scanf("%d%d%d", &n, &p, &t);
	for (int i = 1; i <= p; i++)
	{
		int A, B, L;
		scanf("%d%d%d", &A, &B, &L);
		Edges[i] = e{A, B, L};
		l = min(l, L);
		r = max(r, L);
	}
	sort(Edges + 1, Edges + p + 1);
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (EK(1, n, mid, t, p))
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d", ans);
}
