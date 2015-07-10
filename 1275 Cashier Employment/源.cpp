#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

struct Edge
{
	int To, Pow, Next;

	Edge(int to, int pow, int next) :
		To(to), Pow(pow), Next(next) { }

	Edge() { }
} E[100];

int G[25], dis[25], cnt, num[25], R[25], Cnt[25];
bool inq[25];

void AddEdge(int from, int to, int pow)
{
	E[++cnt] = Edge(to, pow, G[from]);
	G[from] = cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		memset(num, 0, sizeof num);
		for (int i = 1; i <= 24; i++)
			cin >> R[i];
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			num[++x]++;
		}
		int l = 1, r = n, ans = -1;
		while (l <= r)
		{
			int k = (l + r) / 2;
			memset(G, 0, sizeof G);
			cnt = 0;
			for (int i = 1; i <= 24; i++)
			{
				AddEdge(i - 1, i, 0);
				AddEdge(i, i - 1, -num[i]);
			}
			for (int i = 8; i <= 24; i++)
				AddEdge(i - 8, i, R[i]);
			for (int i = 1; i <= 7; i++)
				AddEdge(i + 16, i, R[i] - k);
			AddEdge(0, 24, k);
			fill(dis, dis + 25, INT_MIN);
			memset(inq, 0, sizeof inq);
			memset(Cnt, 0, sizeof Cnt);
			dis[0] = 0;
			queue<int> q;
			q.push(0);
			inq[0] = true;
			bool flag = true;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				inq[u] = false;
				for (int i = G[u]; i != 0; i = E[i].Next)
				{
					int &v = E[i].To;
					int tmp = dis[v];
					dis[v] = max(dis[v], dis[u] + E[i].Pow);
					if (tmp != dis[v] && !inq[v])
					{
						if (++Cnt[v] > n)
						{
							flag = false;
							goto XX;
						}
						q.push(v);
						inq[v] = true;
					}
				}
			}
		XX: if (flag)
			{
				r = k - 1;
				ans = k;
			}
			else l = k + 1;
		}
		if (ans == -1) cout << "No Solution" << endl;
		else cout << ans << endl;
	}
}
