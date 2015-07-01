#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x7fffffff;
pii p[101][41];
double f[41][101][41];
double dis(const pii &a, const pii &b) { return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second)); }
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i][0].first;
		for (int j = 1; j <= p[i][0].first; j++)
		{
			cin >> p[i][j].first >> p[i][j].second;
		}
	}
	for (int i = 1; i <= p[1][0].first; i++)
	{
		for (int j = 1; j <= p[2][0].first; j++) f[i][2][j] = dis(p[1][i], p[2][j]);
		for (int j = 3; j <= n; j++)
		{
			for (int k = 1; k <= p[j][0].first; k++)
			{
				f[i][j][k] = INF;
				for (int l = 1; l <= p[j - 1][0].first; l++)
				{
					f[i][j][k] = min(f[i][j][k], f[i][j - 1][l] + dis(p[j][k], p[j - 1][l]));
				}
			}
		}
	}
	double ans = INF;
	for (int i = 1; i <= p[1][0].first; i++)
	{
		for (int j = 1; j <= p[n][0].first; j++)
		{
			ans = min(ans, f[i][n][j] + dis(p[1][i], p[n][j]));
		}
	}
	cout << (int)(ans * 100) << endl;
}