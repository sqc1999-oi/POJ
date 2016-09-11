#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 0x7fffffff;
int map[51][51];
int G[2000], m = -1;

struct Node
{
	int From, To, Cap, Flow, Next;
} E[400001];

void AddEdge(int from, int to, int cap)
{
	E[++m] = Node{from, to, cap, 0, G[from]};
	G[from] = m;
	E[++m] = Node{to, from, 0, 0, G[to]};
	G[to] = m;
}

int a[2000], p[2000];

int main()
{
	ios::sync_with_stdio(false);
	memset(G, 255, sizeof G);
	int r, c;
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			char ch;
			cin >> ch;
			map[i][j] = ch == '.' ? 0 : 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= r; i++)
	{
		bool found = false;
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] == 1)
			{
				if (!found)
				{
					cnt++;
					found = true;
					AddEdge(0, cnt, 1);
				}
				map[i][j] = cnt;
			}
			else found = false;
		}
	}
	vector<int> v;
	for (int i = 1; i <= c; i++)
	{
		bool found = false;
		for (int j = 1; j <= r; j++)
		{
			if (map[j][i] > 0)
			{
				if (!found)
				{
					cnt++;
					found = true;
					v.push_back(cnt);
				}
				AddEdge(map[j][i], cnt, 1);
			}
			else found = false;
		}
	}
	cnt++;
	for (int i = 0; i < v.size(); i++) AddEdge(v[i], cnt, 1);
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
			if (a[cnt]) break;
		}
		if (!a[cnt]) break;
		for (int i = cnt; i != 0; i = E[p[i]].From)
		{
			E[p[i]].Flow += a[cnt];
			E[p[i] ^ 1].Flow -= a[cnt];
		}
		flow += a[cnt];
	}
	cout << flow;
}
