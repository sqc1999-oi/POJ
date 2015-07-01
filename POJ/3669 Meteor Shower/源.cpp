#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f, N = 400;
const pii P[] = { pii(1, 0), pii(0, 1), pii(-1, 0), pii(0, -1) };
int map[N + 1][N + 1], dis[N + 1][N + 1];

pii operator+(const pii &a, const pii &b) { return pii(a.first + b.first, a.second + b.second); }

bool IsLegal(const pii &a) { return a.first >= 0 && a.first <= N && a.second >= 0 && a.second <= N; }

int main()
{
	ios::sync_with_stdio(false);
	memset(map, 0x3f, sizeof(map));
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		pii p(x, y);
		map[x][y] = min(map[x][y], t);
		for (int i = 0; i < 4; i++)
		{
			pii tmp = p + P[i];
			if (IsLegal(tmp)) map[tmp.first][tmp.second] = min(map[tmp.first][tmp.second], t);
		}
	}
	queue<pii> q;
	memset(dis, 255, sizeof(dis));
	q.push(pii(0, 0));
	dis[0][0] = 0;
	while (!q.empty())
	{
		pii p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pii tmp = p + P[i];
			if (IsLegal(tmp) && dis[tmp.first][tmp.second] == -1)
			{
				if (map[tmp.first][tmp.second] == INF)
				{
					cout << dis[p.first][p.second] + 1;
					return 0;
				}
				else if (map[tmp.first][tmp.second] > dis[p.first][p.second] + 1)
				{
					dis[tmp.first][tmp.second] = dis[p.first][p.second] + 1;
					q.push(tmp);
				}
			}
		}
	}
	cout << -1;
}