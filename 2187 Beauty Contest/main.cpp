#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v, res;
pii operator - (const pii &a, const pii &b) { return pii(a.first - b.first, a.second - b.second); }
int operator ^ (const pii &a, const pii &b) { return a.first*b.second - a.second*b.first; }
int getdis(const pii &a, const pii &b) { return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second); }
bool cmp(const pii &a, const pii &b)
{
	double m = (a - v[0]) ^ (b - v[0]);
	if (m != 0) return m > 0;
	else return getdis(a, v[0]) < getdis(b, v[0]);
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(pii(a,b));
	}
	if (n <= 3) res = v;
	else
	{
		int p = 0;
		for (int i = 1; i < n; i++)
		{
			if (v[i].second < v[p].second || (v[i].second == v[p].second&&v[i].first < v[p].first))
			{
				p = i;
			}
		}
		swap(v[0], v[p]);
		sort(v.begin() + 1, v.end(), cmp);
		res.push_back(v[0]);
		res.push_back(v[1]);
		for (int i = 2; i < n; i++)
		{
			while (res.size() > 2 && ((*(res.end() - 1) - *(res.end() - 2)) ^ (v[i] - *(res.end() - 2))) <= 0) res.pop_back();
			res.push_back(v[i]);
		}
	}
	int ans = 0;
	int pos = 1;
	res.push_back(res[0]);
	for (int i = 0; i < res.size() - 1; i++)
	{
		while (((res[i + 1] - res[i]) ^ (res[pos + 1] - res[i]))>((res[i + 1] - res[i]) ^ (res[pos] - res[i]))) (++pos) %= res.size() - 1;
		ans = max(ans, max(getdis(res[i], res[pos]), getdis(res[i + 1], res[pos + 1])));
	}
	cout << ans;
}
