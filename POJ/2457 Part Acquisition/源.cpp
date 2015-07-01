#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<int> G[1001];
int dis[1001], p[1001];
bool inq[1001];
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	queue<int> q;
	q.push(1);
	inq[1] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			int tmp = dis[v];
			dis[v] = min(dis[v], dis[u] + 1);
			if (tmp != dis[v])
			{
				p[v] = u;
				if (!inq[v])
				{
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	if (dis[k] < 0x3f3f3f3f)
	{
		stack<int> s;
		for (int i = k; i != 0; i = p[i]) s.push(i);
		cout << s.size() << endl;
		while (!s.empty())
		{
			cout << s.top() << endl;
			s.pop();
		}
	}
	else cout << -1 << endl;
}