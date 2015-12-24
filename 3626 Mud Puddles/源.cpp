#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
const pii P[] = { pii(0, 1), pii(1, 0), pii(0, -1), pii(-1, 0) };
int dis[1001][1001];

bool islegal(const pii &a) { return a.first >= 0 && a.first <= 1000 && a.second >= 0 && a.second <= 1000; }

int main()
{
	ios::sync_with_stdio(false);
	memset(dis, 255, sizeof(dis));
	int x, y, n;
	cin >> x >> y >> n;
	x += 500, y += 500;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		a += 500, b += 500;
		dis[a][b] = -2;
	}
	dis[500][500] = 0;
	queue<pii> q;
	q.push(pii(500, 500));
	while (!q.empty())
	{
		pii p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pii tmp = pii(p.first + P[i].first, p.second + P[i].second);
			if (islegal(tmp))
			{
				if (tmp.first == x && tmp.second == y)
				{
					cout << dis[p.first][p.second] + 1;
					return 0;
				}
				if (dis[tmp.first][tmp.second] == -1)
				{
					dis[tmp.first][tmp.second] = dis[p.first][p.second] + 1;
					q.push(tmp);
				}
			}
		}
	}
}
