#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>>
using namespace std;

struct Node
{
	int To, Pow, Next;
} E[30000];

int G[1001], Dis[1001], m, Cnt[1001];
bool InQ[1001];

void AddEdge(int from, int to, int pow)
{
	E[++m] = Node{to,pow,G[from]};
	G[from] = m;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, ml, md;
	cin >> n >> ml >> md;
	for (int i = 2; i <= n; i++) AddEdge(i, i - 1, 0);
	for (int i = 1; i <= ml; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		if (a > b) swap(a, b);
		AddEdge(a, b, d);
	}
	for (int i = 1; i <= md; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		if (a < b) swap(a, b);
		AddEdge(a, b, -d);
	}
	memset(Dis, 0x3f, sizeof Dis);
	Dis[1] = 0;
	InQ[1] = true;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		InQ[u] = false;
		for (int i = G[u]; i != 0; i = E[i].Next)
		{
			int tmp = Dis[E[i].To];
			Dis[E[i].To] = min(Dis[E[i].To], Dis[u] + E[i].Pow);
			if (tmp != Dis[E[i].To]&&!InQ[E[i].To])
			{
				if (++Cnt[E[i].To]>n)
				{
					cout << -1;
					return 0;
				}
				q.push(E[i].To);
				InQ[E[i].To] = true;
			}
		}
	}
	if (Dis[n] == 0x3f3f3f3f) cout << -2;
	else cout << Dis[n];
}
