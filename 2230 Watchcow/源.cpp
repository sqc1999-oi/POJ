#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> G[10001], Edge;
bool vis[100001];
void euler(int u)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		if (!vis[G[u][i]])
		{
			vis[G[u][i]] = true;
			euler(Edge[G[u][i]]);
			cout << Edge[G[u][i]] << endl;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(Edge.size());
		Edge.push_back(y);
		G[y].push_back(Edge.size());
		Edge.push_back(x);
	}
	euler(1);
	cout << 1 << endl;
}