#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, ans = 0x7fffffff;
string s[8];
bool vis[8];
string join(const string &s1, const string &s2)
{
	if (s1 == "") return s2;
	for (int i = min(s1.size(), s2.size()); i > 0; i--)
	{

		if (s1.substr(s1.size() - i) == s2.substr(0, i))
		{
			return s1.substr(0, s1.size() - i) + s2;
		}
	}
	return s1 + s2;
}
void dfs(string ss)
{
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			flag = true;
			vis[i] = true;
			dfs(join(ss, s[i]));
			vis[i] = false;
		}
	}
	if (!flag)
	{
		ans = min(ans, (int)ss.size());
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	dfs("");
	cout << ans << endl;
}
