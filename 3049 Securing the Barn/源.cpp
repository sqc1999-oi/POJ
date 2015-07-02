#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int l, c;
vector<char> ch;
int map[26];
bool isvowel(char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }
void dfs(string s, int v, int c)
{
	if (s.size() == l)
	{
		if (v >= 1 && c >= 2)
		{
			cout << s << endl;
		}
		return;
	}
	for (vector<char>::iterator it = s.size() != 0 ? upper_bound(ch.begin(), ch.end(), s[s.size() - 1])  : ch.begin(); it != ch.end(); it++)
	{
		dfs(s + *it, v + isvowel(*it), c + !isvowel(*it));
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> l >> c;
	for (int i = 1; i <= c; i++)
	{
		char x;
		do cin >> x; while (x == ' ');
		ch.push_back(x);
	}
	sort(ch.begin(), ch.end());
	dfs("", 0, 0);
}