#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int n, m;
bool map[101][101];
const pii P[] = { pii{1,0},pii{0,1},pii{-1,0},pii{0,-1},pii{1,1},pii{-1,-1},pii{1,-1},pii{-1,1} };
pii operator + (pii a, pii b) { return pii{ a.first + b.first,a.second + b.second }; }
void dfs(pair<int, int> p)
{
	map[p.first][p.second] = false;
	for (int i = 0; i < 8; i++)
	{
		pii tmp = p + P[i];
		if (tmp.first > 0 && tmp.first <= n&&tmp.second > 0 && tmp.second <= m&&map[tmp.first][tmp.second])
		{
			dfs(tmp);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			map[i][j] = ch == 'W';
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j])
			{
				cnt++;
				dfs(pii{ i,j });
			}
		}
	}
	cout << cnt << endl;
}