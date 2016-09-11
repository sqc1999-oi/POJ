#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
struct Edge
{
	int To, Time;
	double Pow;
} E[5001];
const double EPS = 1e-10;
vector<int> G[1001];
int f[1001], cnt[1001];
double dis[1001];
bool inq[1001];
bool Spfa(int n)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		dis[i] = 0;
		inq[i] = true;
	}
	memset(cnt, 0x00, sizeof cnt);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = E[G[u][i]].To;
			double tmp = dis[v];
			dis[v] = min(dis[v], dis[u] + E[G[u][i]].Pow);
			if (tmp != dis[v])
			{
				if (++cnt[v] > n) return true;
				q.push(v);
				inq[v] = true;
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int l, p;
	cin >> l >> p;
	for (int i = 1; i <= l; i++) cin >> f[i];
	for (int i = 1; i <= p; i++)
	{
		int l1, l2, t;
		cin >> l1 >> l2 >> t;
		G[l1].push_back(i);
		E[i].To = l2;
		E[i].Time = t;
	}
	double L = 0, R = 1000;
	while (fabs(L- R) > EPS)
	{
		double mid = (L + R) / 2;
		for (int i = 1; i <= p; i++) E[i].Pow = mid*E[i].Time - f[E[i].To];
		if (Spfa(l)) L = mid;
		else R = mid;
	}
	cout << fixed << setprecision(2) << L << endl;
}
