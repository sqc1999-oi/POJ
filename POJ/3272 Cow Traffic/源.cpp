#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<int> G[2][5001];
vector<pair<int, int> > E;
int in[2][5001], cnt[2][5001], n, m;

void topo(int flag)
{
	queue<int> q;
	for (int i = 1; i <= n; i++) if (in[flag][i] == 0) q.push(i), cnt[flag][i] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < G[flag][u].size(); i++)
		{
			int v = G[flag][u][i];
			cnt[flag][v] += cnt[flag][u];
			if (--in[flag][v] == 0) q.push(v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		E.push_back(make_pair(min(a, b), max(a, b)));
		G[0][min(a, b)].push_back(max(a, b));
		G[1][max(a, b)].push_back(min(a, b));
		in[0][max(a, b)]++;
		in[1][min(a, b)]++;
	}
	topo(0), topo(1);
	int ans = 0;
	for (int i = 0; i < m; i++) ans = max(ans, cnt[0][E[i].first] * cnt[1][E[i].second]);
	cout << ans;
}