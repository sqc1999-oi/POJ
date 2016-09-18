#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int trie[200001][27], cnt;

void insert(int u, const string& s, int pos)
{
	trie[u][26]++;
	if (pos == s.length()) return;
	int v = s[pos] - 'a';
	if (trie[u][v] == 0) trie[u][v] = ++cnt;
	insert(trie[u][v], s, pos + 1);
}

int search(int u, const string& s, int pos)
{
	if (pos == s.length()) return 0;
	if (u != 0 && trie[u][26] == 1) return 0;
	return search(trie[u][s[pos] - 'a'], s, pos + 1) + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<string> v;
	string s;
	while (cin >> s)
	{
		insert(0, s, 0);
		v.push_back(s);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ' << v[i].substr(0, search(0, v[i], 0)) << endl;
	}
}
