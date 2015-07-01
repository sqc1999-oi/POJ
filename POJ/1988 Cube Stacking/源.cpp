#include <iostream>
#include <algorithm>
using namespace std;
int p[30001], d[30001], s[30001];
int find(int x)
{
	if (x == p[x]) return x;
	int t = p[x];
	p[x] = find(p[x]);
	d[x] += d[t];
	return p[x];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= 30000; i++) p[i] = i, d[i] = 0, s[i] = 1;
	for (int i = 1; i <= n; i++)
	{
		char op;
		cin >> op;
		if (op == 'M')
		{
			int x, y;
			cin >> x >> y;
			x = find(x);
			y = find(y);
			p[y] = x;
			d[y] = s[x];
			s[x] += s[y];
		}
		else
		{
			int x;
			cin >> x;
			cout << s[find(x)] - d[x] - 1 << endl;
		}
	}
}