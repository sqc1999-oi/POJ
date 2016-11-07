#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;
typedef pair<int, int> pii;
const pii P[] = {pii(1, 0), pii(0, 1), pii(-1, 0), pii(0, -1)};

pii operator +(const pii& a, const pii& b)
{
	return pii(a.first + b.first, a.second + b.second);
}

int map[101][101];
double dis[101][101];
bool inq[101][101];

int main()
{
	ios::sync_with_stdio(false);
	int v, r, c;
	cin >> v >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= r; i++) fill(dis[i] + 1, dis[i] + 1 + c, 1e10);
	queue<pii> q;
	q.push(pii(1, 1));
	inq[1][1] = true;
	dis[1][1] = 0;
	while (!q.empty())
	{
		pii u = q.front();
		q.pop();
		inq[u.first][u.second] = false;
		double t;
		t = 1ll << abs(map[1][1] - map[u.first][u.second]);
		if (map[1][1] < map[u.first][u.second]) t = 1.0 / t;
		t *= v;
		t = 1.0 / t;
		for (int i = 0; i < 4; i++)
		{
			pii v = u + P[i];
			if (v.first > 0 && v.first <= r && v.second > 0 && v.second <= c)
			{
				double tmp = dis[v.first][v.second];
				dis[v.first][v.second] = min(dis[v.first][v.second], dis[u.first][u.second] + t);
				if (tmp != dis[v.first][v.second] && !inq[v.first][v.second])
				{
					q.push(v);
					inq[v.first][v.second] = true;
				}
			}
		}
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << dis[r][c];
}
