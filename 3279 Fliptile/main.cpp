#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
typedef pair<int, int> pii;
const pii P[] = { pii(1, 0), pii(0, 1), pii(-1, 0), pii(0, -1) };
int map[16][16], tmp[16][16], sample[16][16], step[16][16];
int m, n;

pii operator+(const pii &a, const pii &b) { return pii(a.first + b.first, a.second + b.second); }

bool islegal(const pii &p) { return p.first > 0 && p.first <= m && p.second > 0 && p.second <= n; }

void flip(const pii &p)
{
	tmp[p.first][p.second] = !tmp[p.first][p.second];
	for (int i = 0; i < 4; i++)
	{
		pii t = p + P[i];
		if (islegal(t)) tmp[t.first][t.second] = !tmp[t.first][t.second];
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) cin >> map[i][j];
	for (int i = 0; i < (1 << n); i++)
	{
		memcpy(tmp, map, sizeof(map));
		int x = i;
		for (int j = 1; j <= n; j++)
		{
			if (x % 2 == 1)
			{
				step[1][j] = 1;
				flip(pii(1, j));
			}
			x /= 2;
		}
		for (int j = 2; j <= m; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (tmp[j - 1][k])
				{
					step[j][k] = 1;
					flip(pii(j, k));
				}
			}
		}
		if (memcmp(tmp, sample, sizeof(tmp)) == 0)
		{
			for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					cout << step[i][j] << ' ';
				}
				cout << endl;
			}
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
}
