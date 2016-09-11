#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int Next[1000001];

int main()
{
	ios::sync_with_stdio(false);
	string s;
	while (cin >> s && s != ".")
	{
		int j = 0;
		Next[0] = Next[1] = 0;
		for (int i = 1; i < s.length(); i++)
		{
			while (j > 0 && s[i] != s[j])
				j = Next[j];
			if (s[i] == s[j]) j++;
			Next[i + 1] = j;
		}
		if (s.length() % (s.length() - Next[s.length()]) == 0) cout << s.length() / (s.length() - Next[s.length()]) << endl;
		else cout << 1 << endl;
	}
}
