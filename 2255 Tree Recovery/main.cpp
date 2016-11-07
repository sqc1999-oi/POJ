#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void solve(string pre, string in)
{
	if (pre.size() <= 1)
	{
		cout << pre;
		return;
	}
	int pos = in.find(pre[0]);
	solve(pre.substr(1, pos), in.substr(0, pos));
	solve(pre.substr(1 + pos), in.substr(pos + 1));
	cout << pre[0];
}
int main()
{
	ios::sync_with_stdio(false);
	string a, b;
	while (cin >> a >> b)
	{
		solve(a, b);
		cout << endl;
	}
}
