#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int Next[400001];
int main()
{
	ios::sync_with_stdio(false);
	string s;
	while (cin >> s)
	{
		int j = 0;
		Next[0] = Next[1] = 0;
		for (int i = 1; i < s.length();i++)
		{
			while (j > 0 && s[i] != s[j]) j = Next[j];
			if (s[i] == s[j]) j++;
			Next[i + 1] = j;
		}
		stack<int> S;
		int x = s.length();
		while (x != 0) S.push(x), x = Next[x];
		while (!S.empty()) cout << S.top() << ' ', S.pop();
		cout << endl;
	}
}
