#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <stack>
using namespace std;
bool vis[26];
int main()
{
	ios::sync_with_stdio(false);
	string s;
	getline(cin, s);
	stack<char> s1, s2;
	for (int i = 0; i < s.size(); i++)
	{
		if (isupper(s[i]))
		{
			if (!(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') && !vis[s[i] - 'A'])	vis[s[i] - 'A'] = true;
			else continue;
		}
		s1.push(s[i]);
	}
	while (!s1.empty() && s1.top() == ' ') s1.pop();
	while (!s1.empty())
	{
		if (s2.empty() || !(s1.top() == ' ' && (s2.top() == ' ' || s2.top() == ',' || s2.top() == '.' || s2.top() == '?' || s2.top() == '!'))) s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty() && s2.top() == ' ') s2.pop();
	while (!s2.empty())
	{
		cout << s2.top();
		s2.pop();
	}
}
