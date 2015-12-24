#include <iostream>
#include <algorithm>
using namespace std;
int n, m, cnt, S[61], map[101], f[101][61][61], Cnt[60];

string to_string(int x)
{
	string ans;
	do
	{
		ans = char(x % 2 + '0') + ans;
		x /= 2;
	}
	while (x != 0);
	while (ans.length() < m) ans = '0' + ans;
	return ans;
}

bool pre_test(int s)
{
	int last = -2;
	for (int i = 1; i <= m; i++)
	{
		if (s & 1 << i - 1)
		{
			if (i - last <= 2) return false;
			last = i;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(f, 0xff, sizeof f);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char x;
			cin >> x;
			(map[i] *= 2) += x == 'P';
		}
	}
	for (int i = 0; i < 1 << m; i++)
		if (pre_test(i))
		{
			S[++cnt] = i;
			for (int j = 1; j <= m; j++)
				if (i & 1 << j - 1)
					Cnt[cnt]++;
			if ((i & map[1]) == i)
				f[1][1][cnt] = Cnt[cnt];
		}
	if (n > 1)
		for (int i = 1; i <= cnt; i++)
		{
			if (f[1][1][i] == -1) continue;
			for (int j = 1; j <= cnt; j++)
				if ((S[j] & map[2]) == S[j] && !(S[i] & S[j]))
					f[2][i][j] = f[1][1][i] + Cnt[j];
		}
	for (int i = 3; i <= n; i++)
		for (int j = 1; j <= cnt; j++)
			for (int k = 1; k <= cnt; k++)
			{
				if (f[i - 1][j][k] == -1) continue;
				for (int l = 1; l <= cnt; l++)
					if (!(S[l] & S[j]) && !(S[l] & S[k]) && (S[l] & map[i]) == S[l])
						f[i][k][l] = max(f[i][k][l], f[i - 1][j][k] + Cnt[l]);
			}
	int ans = 0;
	for (int i = 1; i <= cnt; i++)
		for (int j = 1; j <= cnt; j++)
			ans = max(ans, f[n][i][j]);
	cout << ans << endl;
}
