#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int p[1001], Cnt[1001][2], f[1001][1001][2];
bool r[1001], vis[1001];
vector<int> mem[1001][2];

int find(int x)
{
	if (x == p[x]) return x;
	int t = p[x];
	p[x] = find(p[x]);
	r[x] = r[x] == r[t];
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false);
	int n, p1, p2;
	while (cin >> n >> p1 >> p2)
	{
		if (n == 0 && p1 == 0 && p2 == 0) break;
		for (int i = 1; i <= p1 + p2; i++) p[i] = i , r[i] = 1;
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			string s;
			cin >> x >> y >> s;
			int xx = find(x), yy = find(y);
			p[xx] = yy;
			if (s == "yes") r[xx] = r[x] == r[y];
			else r[xx] = r[x] != r[y];
		}
		int cnt = 0;
		for (int i = 1; i <= p1 + p2; i++) mem[i][0].clear() , mem[i][1].clear();
		memset(vis, 0, sizeof vis);
		memset(Cnt, 0, sizeof Cnt);
		for (int i = 1; i <= p1 + p2; i++)
			if (!vis[i])
			{
				cnt++;
				int x = find(i);
				for (int j = 1; j <= p1 + p2; j++)
					if (find(j) == x)
					{
						vis[j] = true;
						Cnt[cnt][r[j]]++;
						mem[cnt][r[j]].push_back(j);
					}
			}
		memset(f, 0, sizeof f);
		f[0][0][0] = 1;
		for (int i = 1; i <= cnt; i++)
		{
			for (int j = 0; j <= p1; j++)
			{
				if (j - Cnt[i][0] >= 0) f[i][j][0] += f[i - 1][j - Cnt[i][0]][0];
				if (j - Cnt[i][1] >= 0) f[i][j][0] += f[i - 1][j - Cnt[i][1]][0];
				if (f[i][j][0] == 1)
				{
					if (f[i - 1][j - Cnt[i][0]][0]) f[i][j][1] = 0;
					else f[i][j][1] = 1;
				}
			}
		}
		if (f[cnt][p1][0] != 1)
		{
			cout << "no" << endl;
			continue;
		}
		vector<int> ans;
		for (int i = cnt; i > 0; i--)
		{
			for (int j = 0; j < mem[i][f[i][p1][1]].size(); j++) ans.push_back(mem[i][f[i][p1][1]][j]);
			p1 -= Cnt[i][f[i][p1][1]];
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
		cout << "end" << endl;
	}
}
