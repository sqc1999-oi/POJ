#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int m, t, u, f, d;
	cin >> m >> t >> u >> f >> d;
	int ti = 0;
	for (int i = 1; i <= t; i++)
	{
		char ch;
		cin >> ch;
		if (ch == 'f') ti += f * 2;
		else ti += u + d;
		if (ti > m)
		{
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << t << endl;
}
