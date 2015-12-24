#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

struct Edge
{
	int from, to;
	double pow;
	Edge(int from, int to, double pow) :from(from), to(to), pow(pow) {}
	bool operator<(const Edge &e) const { return pow < e.pow; }
};

typedef pair<int, int> pii;
pii p[1001];
int f[1001];
vector<Edge> e;

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

double getdis(const pii &a, const pii &b) { return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); }

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			e.push_back(Edge(i, j, getdis(p[i], p[j])));
		}
	}
	sort(e.begin(), e.end());
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		int xx = find(x), yy = find(y);
		if (xx != yy) f[xx] = yy;
	}
	double ans = 0;
	for (int i = 0; i < e.size(); i++)
	{
		int x = find(e[i].from), y = find(e[i].to);
		if (x != y)
		{
			f[x] = y;
			ans += e[i].pow;
		}
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << ans;
}
