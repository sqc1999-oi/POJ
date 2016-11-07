#include <iostream>
#include <algorithm>
using namespace std;
char map[6][6];
int bin[6][6], ans = 0;
bool visited[1 << 25], visiting[6][6];
bool vis(int x, int y) 
{
	if (x < 1 || x>5 || y < 1 || y>5) return false;
	return visiting[x][y];
}
void dfs(int tot, int cnt, int s)
{
	if (tot == 7)
	{
		if (cnt > 3) ans++;
		return;
	}
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (!visiting[i][j] && (vis(i + 1, j) || vis(i - 1, j) || vis(i, j + 1) || vis(i, j - 1)))
			{
				int k = s | bin[i][j];
				if (!visited[k])
				{
					visited[k] = true;
					visiting[i][j] = true;
					dfs(tot + 1, cnt + (map[i][j] == 'J'), k);
					visiting[i][j] = false;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int cnt = -1;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> map[i][j];
			bin[i][j] = 1 << ++cnt;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			visited[bin[i][j]] = true;
			visiting[i][j] = true;
			dfs(1, map[i][j] == 'J', bin[i][j]);
			visiting[i][j] = false;
		}
	}
	cout << ans;
}
