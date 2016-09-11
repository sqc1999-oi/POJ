#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int m;
	cin >> m;
	while (m--)
	{
		int n;
		cin >> n;
		int f = 0, u = 2, l = 4, x = 0, y = 0, z = 0;
		while (n--)
		{
			string d;
			int s;
			cin >> d >> s;
			int tmp;
			switch (d[0])
			{
			case 'b':
				(f += 3) %= 6;
				(l += 3) %= 6;
				break;
			case 'l':
				tmp = f;
				f = l;
				l = (tmp + 3) % 6;
				break;
			case 'r':
				tmp = l;
				l = f;
				f = (tmp + 3) % 6;
				break;
			case 'u':
				tmp = f;
				f = u;
				u = (tmp + 3) % 6;
				break;
			case 'd':
				tmp = u;
				u = f;
				f = (tmp + 3) % 6;
				break;
			}
			switch (f)
			{
			case 0:
				x += s;
				break;
			case 1:
				y += s;
				break;
			case 2:
				z += s;
				break;
			case 3:
				x -= s;
				break;
			case 4:
				y -= s;
				break;
			case 5:
				z -= s;
				break;
			}
		}
		cout << x << ' ' << y << ' ' << z << ' ' << f << endl;
	}
}
