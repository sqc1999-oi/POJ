#include <iostream>
#include <algorithm>

using namespace std;
char ch[2001];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> ch[i];
	int l = 1, r = n, cnt = 0;
	while (l <= r)
	{
		int i = l, j = r;
		for (; i <= j && ch[i] == ch[j]; i++, j--);
		if (ch[i] < ch[j]) cout << ch[l++];
		else cout << ch[r--];
		if (++cnt == 80)
		{
			cout << endl;
			cnt = 0;
		}
	}
}
