#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int Next[10001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--)
	{
		string t, p;
		cin >> p >> t;
		Next[0] = Next[1] = 0;
		for (int i = 1, j = 0; i < p.length(); i++)
		{
			while (j > 0 && p[i] != p[j]) j = Next[j];
			if (p[i] == p[j]) j++;
			Next[i + 1] = j;
		}
		int ans = 0;
		for (int i = 0, j = 0; i < t.length(); i++)
		{
			while (j > 0 && t[i] != p[j]) j = Next[j];
			if (t[i] == p[j]) j++;
			if (j == p.length()) ans++, j = Next[j];
		}
		cout << ans << endl;
	}
}
