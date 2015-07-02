#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge
{
	int u, v, w;
	bool operator<(const Edge &a) const { return w>a.w; }
};
int p[1001];
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
vector<Edge> Edges;
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Edges.push_back(Edge{ a,b,c });
	}
	sort(Edges.begin(), Edges.end());
	for (int i = 1; i <= n; i++) p[i] = i;
	int ans = 0, cnt = 0;
	for (int i = 0; i < Edges.size(); i++)
	{
		Edge &e = Edges[i];
		int x = find(e.u), y = find(e.v);
		if (x != y)
		{
			p[x] = y;
			ans += e.w;
			cnt++;
		}
	}
	if (cnt == n - 1) cout << ans;
	else cout << -1;
}