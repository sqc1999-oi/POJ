#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int G[402], m = -1, a[402], p[402];
const int INF = 0x7fffffff;
struct Node
{
	int From, To, Cap, Flow, Next;
} E[20301];
void AddEdge(int from, int to, int cap)
{
	E[++m] = Node { from, to, cap, 0, G[from] };
	G[from] = m;
	E[++m] = Node { to, from, 0, 0, G[to] };
	G[to] = m;
}
int main()
{
	ios::sync_with_stdio(false);
	memset(G, 255, sizeof G);
	int n, f, d;
	cin >> n >> f >> d;
	for (int i = 1; i <= n; i++)
		AddEdge(f + i, f + n + i, 1);
	for (int i = 1; i <= f; i++)
		AddEdge(0, i, 1);
	for (int i = 1; i <= d; i++)
		AddEdge(f + n * 2 + i, f + n * 2 + d + 1, 1);
	for (int i = 1; i <= n; i++)
	{
		int fi, di;
		cin >> fi >> di;
		for (int j = 1; j <= fi; j++)
		{
			int x;
			cin >> x;
			AddEdge(x, f + i, 1);
		}
		for (int j = 1; j <= di; j++)
		{
			int x;
			cin >> x;
			AddEdge(f + n + i, f + n * 2 + x, 1);
		}
	}
	int t = n * 2 + f + d + 1;
	int flow = 0;
	while (true)
	{
		memset(a, 0, sizeof a);
		a[0] = INF;
		queue<int> q;
		q.push(0);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = G[u]; i != -1; i = E[i].Next)
			{
				if (!a[E[i].To] && E[i].Cap > E[i].Flow)
				{
					p[E[i].To] = i;
					a[E[i].To] = min(a[u], E[i].Cap - E[i].Flow);
					q.push(E[i].To);
				}
			}
			if (a[t]) break;
		}
		if (!a[t]) break;
		for (int i = t; i != 0; i = E[p[i]].From)
		{
			E[p[i]].Flow += a[t];
			E[p[i] ^ 1].Flow -= a[t];
		}
		flow += a[t];
	}
	cout << flow;
}
