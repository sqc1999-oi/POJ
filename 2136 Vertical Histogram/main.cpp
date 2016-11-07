#include<iostream>
#include<algorithm>
#include<vector>
#include<cctype>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int cnt[26] = {};
	char ch;
	while (cin >> ch)
	{
		if (isupper(ch)) cnt[ch - 'A']++;
	}
	for (int i = *max_element(cnt, cnt + 26); i > 0; i--)
	{
		for (int j = 0; j < 26; j++)
		{
			if (*max_element(cnt + j, cnt + 26) < i) break;
			cout << (i > cnt[j] ? ' ' : '*') << ' ';
		}
		cout << endl;
	}
	for (char i = 'A'; i <= 'Z'; i++) cout << i << ' ';
	cout << endl;
}
