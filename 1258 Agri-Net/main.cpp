#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Edge
{
	int u, v, w;

	bool operator <(const Edge& a) const
	{
		return w < a.w;
	}
};

vector<Edge> Edges;
int p[101];

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int w;
				cin >> w;
				Edge e = {i,j,w};
				Edges.push_back(e);
			}
		}
		sort(Edges.begin(), Edges.end());
		for (int i = 1; i <= n; i++) p[i] = i;
		int ans = 0;
		for (vector<Edge>::iterator it = Edges.begin(); it != Edges.end(); ++it)
		{
			int x = find(it->u), y = find(it->v);
			if (x != y)
			{
				p[x] = y;
				ans += it->w;
			}
		}
		cout << ans << endl;
		Edges.clear();
	}
}
