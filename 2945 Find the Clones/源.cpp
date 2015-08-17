#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string s[20001];
int trie[400001][27], cnt, ans[20001];

void insert(int u, const string& s, int pos)
{
	if (pos == s.length())
	{
		trie[u][26]++;
		return;
	}
	int v = s[pos] - 'A';
	if (trie[u][v] == 0) trie[u][v] = ++cnt;
	insert(trie[u][v], s, pos + 1);
}

void getans(int u)
{
	if (trie[u][26] > 0) ans[trie[u][26]]++;
	for (int i = 0; i < 26; i++)
		if (trie[u][i] != 0) getans(trie[u][i]);
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m && !(n == 0 && m == 0))
	{
		cnt = 0;
		memset(ans, 0x00, sizeof ans);
		memset(trie, 0x00, sizeof trie);
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			insert(0, s[i], 0);
		}
		getans(0);
		for (int i = 1; i <= n; i++)
			cout << ans[i] << endl;
	}
}
