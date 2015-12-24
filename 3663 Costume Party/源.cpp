#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x <= s) v.push_back(x);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i] + v[j] <= s) ans++;
			else break;
		}
	}
	cout << ans << endl;
}
