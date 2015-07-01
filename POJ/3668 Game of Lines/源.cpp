#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<int, int> pii;
set<pii> s;
pii a[201];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			pii p(a[i].first - a[j].first, a[i].second - a[j].second);
			int g = gcd(p.first, p.second);
			s.insert(pii(p.first / g, p.second / g));
		}
	}
	cout << s.size();
}