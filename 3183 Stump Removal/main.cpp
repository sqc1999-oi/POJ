#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int last = 0;
	bool up = true;
	for (int i = 1; i <= n + 1; i++)
	{
		int x;
		if (i <= n) cin >> x; else x = 0;
		if (x > last) up = true;
		else
		{
			if (up) cout << i - 1 << endl;
			up = x == last;
		}
		last = x;
	}
}
