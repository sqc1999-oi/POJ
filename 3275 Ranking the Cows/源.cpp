#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> G[1001][2];
bool map[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a][0].push_back(b);
		G[b][1].push_back(a);
		map[a][b] = true;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 0; i < G[k][1].size(); i++)
		for (int j = 0; j < G[k][0].size(); j++)
		{
			if (!map[G[k][1][i]][G[k][0][j]])
			{
				map[G[k][1][i]][G[k][0][j]] = true;
				G[G[k][1][i]][0].push_back(G[k][0][j]);
				G[G[k][0][j]][1].push_back(G[k][1][i]);
			}
		}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += G[i][0].size() + G[i][1].size();
	cout << (n * (n - 1) - ans) / 2;
}