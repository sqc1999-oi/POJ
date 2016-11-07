#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const pii P[] = { pii(0,1),pii(0,-1),pii(1,0),pii(1,1),pii(1,-1),pii(-1,0),pii(-1,1),pii(-1,-1) };
const int INF = 0x3f3f3f3f;
bool map[51][51];
int dis[51][51], n, m;
inline int &Dis(const pii &p) { return dis[p.first][p.second]; }
inline bool &Map(const pii &p) { return map[p.first][p.second]; }
inline pii operator+(const pii &a, const pii &b) { return pii(a.first + b.first, a.second + b.second); }
inline bool islegal(const pii &p) { return p.first > 0 && p.first <= n&&p.second > 0 && p.second <= m&&!Map(p); }
int bfs(pii s, pii t)
{
	int ans = 0;
	for (int i = 1; i <= 2; i++)
	{
		memset(dis, 0x3f, sizeof(dis));
		queue<pii> q;
		if (i == 1)
		{
			for (int j = 2; j <= 4; j++)
			{
				if (islegal(s + P[j]))
				{
					q.push(s + P[j]);
					Dis(s + P[j]) = 1;
				}
			}
		}
		else
		{
			for (int j = 5; j <= 7; j++)
			{
				if (islegal(s + P[j]))
				{
					q.push(s + P[j]);
					Dis(s + P[j]) = 1;
				}
			}
		}
		int x = INF;
		while (!q.empty())
		{
			pii p = q.front();
			q.pop();
			if (p == t)
			{
				x = Dis(p);
				break;
			}
			for (int j = 0; j < 8; j++)
			{
				pii tmp = p + P[j];
				if (islegal(tmp) && Dis(tmp) == INF)
				{
					Dis(tmp) = Dis(p) + 1;
					q.push(tmp);
				}
			}
		}
		ans += x;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	pii t, p;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			if (ch == 'X') map[i][j] = true, p = pii(i, j);
			else if (ch == '*') t = pii(i, j);
		}
	}
	int ans = INF;
	if (t.first == p.first&&t.second > p.second)
	{
		while (Map(p)) p.second--;
		for (int i = p.second; i > 0; i--) Map(pii(p.first, i)) = true;
		for (int i = p.second; i > 0; i--) ans = min(ans, bfs(pii(p.first, i), t));
	}
	else
	{
		while (Map(p)) p.second++;
		for (int i = p.second; i <= m; i++) Map(pii(p.first, i)) = true;
		for (int i = p.second; i <= m; i++) ans = min(ans, bfs(pii(p.first, i), t));
	}
	cout << ans;
}
