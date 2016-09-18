#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
typedef pair<int, int> pii;
const pii P[] = { pii{ 1, 0 }, pii{ 0, 1 }, pii{ -1, 0 }, pii{ 0, -1 } };
int a[101][101], n, minv = 0x7fffffff, maxv = 0;
bool vis[101][101];

pii operator+(const pii &a, const pii &b)
{
	return pii{ a.first + b.first, a.second + b.second };
}

bool bfs(int lb, int ub)
{
	memset(vis, 0, sizeof(vis));
	queue<pii> q;
	if (a[1][1] > ub || a[1][1] < lb) return false;
	q.push(pii{ 1, 1 });
	vis[1][1] = true;
	while (!q.empty())
	{
		pii p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pii tmp = p + P[i];
			if (tmp.first <= n && tmp.first > 0 && tmp.second <= n && tmp.second > 0 && !vis[tmp.first][tmp.second] &&
				a[tmp.first][tmp.second] <= ub && a[tmp.first][tmp.second] >= lb)
			{
				if (tmp.first == n && tmp.second == n) return true;
				vis[tmp.first][tmp.second] = true;
				q.push(tmp);
			}
		}
	}
	return false;
}

bool check(int diff)
{
	for (int i = minv; i + diff <= maxv; i++)
	{
		if (bfs(i, i + diff)) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			minv = min(minv, a[i][j]);
			maxv = max(maxv, a[i][j]);
		}
	}
	int l = 0, r = maxv - minv, ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
}
