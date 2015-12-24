#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int, int> pii;
pii operator + (pii a, pii b) { return pii{ a.first + b.first,a.second + b.second }; }
const pii P[] = { pii{0,1},pii{1,0},pii{0,-1},pii{-1,0} };
int map[6][6];
set<int> s;
void dfs(pii p, int hash, int n)
{
	if (n == 6)	s.insert(hash);
	else
	{
		for (int i = 0; i < 4; i++)
		{
			pii tmp = p + P[i];
			if (tmp.first > 0 && tmp.first <= 5 && tmp.second > 0 && tmp.second <= 5)
			{
				dfs(tmp, hash * 10 + map[tmp.first][tmp.second], n + 1);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			dfs(pii{ i,j }, 0, 0);
		}
	}
	cout << s.size();
}
