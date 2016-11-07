#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int rmin[251][251], rmax[251][251], gmin[251][251], gmax[251][251];
typedef pair<int, int> pii;
int main()
{
	ios::sync_with_stdio(false);
	int n, b, k;
	cin >> n >> b >> k;
	deque<pii> qmin, qmax;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < b; j++)
		{
			int x;
			cin >> x;
			while (!qmin.empty() && qmin.back().first > x) qmin.pop_back();
			qmin.push_back(pii{ x,j });
			while (!qmax.empty() && qmax.back().first < x) qmax.pop_back();
			qmax.push_back(pii{ x,j });
		}
		for (int j = b; j <= n; j++)
		{
			while (!qmin.empty() && qmin.front().second <= j - b) qmin.pop_front();
			while (!qmax.empty() && qmax.front().second <= j - b) qmax.pop_front();
			int x;
			cin >> x;
			while (!qmin.empty() && qmin.back().first > x) qmin.pop_back();
			qmin.push_back(pii{ x,j });
			while (!qmax.empty() && qmax.back().first < x) qmax.pop_back();
			qmax.push_back(pii{ x,j });
			rmin[i][j - b + 1] = qmin.front().first;
			rmax[i][j - b + 1] = qmax.front().first;
		}
		qmin.clear();
		qmax.clear();
	}
	for (int i = 1; i <= n - b + 1; i++)
	{
		for (int j = 1; j < b; j++)
		{
			int x = rmin[j][i], y = rmax[j][i];
			while (!qmin.empty() && qmin.back().first > x) qmin.pop_back();
			qmin.push_back(pii{ x,j });
			while (!qmax.empty() && qmax.back().first < y) qmax.pop_back();
			qmax.push_back(pii{ y,j });
		}
		for (int j = b; j <= n; j++)
		{
			while (!qmin.empty() && qmin.front().second <= j - b) qmin.pop_front();
			while (!qmax.empty() && qmax.front().second <= j - b) qmax.pop_front();
			int x = rmin[j][i], y = rmax[j][i];
			while (!qmin.empty() && qmin.back().first > x) qmin.pop_back();
			qmin.push_back(pii{ x,j });
			while (!qmax.empty() && qmax.back().first < y) qmax.pop_back();
			qmax.push_back(pii{ y,j });
			gmin[j - b + 1][i] = qmin.front().first;
			gmax[j - b + 1][i] = qmax.front().first;
		}
		qmin.clear();
		qmax.clear();
	}
	for (int i = 1; i <= k; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << gmax[a][b] - gmin[a][b] << endl;
	}
}
