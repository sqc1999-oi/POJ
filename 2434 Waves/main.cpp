#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int P, B1, B2, R, back_dis, map[16][16];
inline void put(int x, int y, int h)
{
	if (x < -4 || x > 4 || y < -4 || y > 4)
		return;
	map[y + 4][x + 4] += h;
}
inline void left(int x, int y, int t, int h, int dir)
{
	int i;

	if (!dir) x -= t;
	else 
	{
		i = min(t, B1 - x - 1);
		t -= i;
		x += i;
		if (t > 1) {
			t--;
			x -= t;
		}
	}
	put(x, y, h);
}
inline void right(int x, int y, int t, int h, int dir)
{
	int i;

	if (!dir) 
	{
		i = min(t, x - B2 - 1);
		t -= i;
		x -= i;
		if (t > 1) {
			t--;
			x += t;
		}
	}
	else x += t;
	put(x, y, h);
}
inline void mid(int x, int y, int t, int h, int dir)
{
	int i;
	if (!dir) 
	{
		i = min(t, x - B1 - 1);
		t -= i;
		x -= i;
	}
	else 
	{
		i = min(t, B2 - x - 1);
		t -= i;
		x += i;
	}
	if (t > 1)
	{
		i = t / back_dis;
		if (i) t -= i*back_dis;
	}
	if (!t)
	{
		put(x, y, h);
		return;
	}
	t--;
	mid(x, y, t, h, !dir);
}
inline void point(int x, int y, int t, int h, int dir)
{
	if (x < B1)
		left(x, y, t, h, dir);
	else if (x > B1 && x < B2)
		mid(x, y, t, h, dir);
	else
		right(x, y, t, h, dir);
}
inline void Pair(int x, int y, int t, int h)
{
	if (t > R)
		return;
	if (t == R)
		put(x, y, h);
	else {
		point(x, y, R - t, h, 0);
		point(x, y, R - t, h, 1);
	}
}
inline void wave(int x, int y, int t, int h)
{
	int i;

	for (i = -4; i <= 4; i++) Pair(x, i, t + abs(y - i), h);
}
int main()
{
	ios::sync_with_stdio(false);
	int i, x, y, t;
	cin >> P >> B1 >> B2 >> R;
	if (B1 > B2)
	{
		i = B2;
		B2 = B1;
		B1 = i;
	}
	back_dis = 2 * (B2 - B1) - 2;
	while (P--) 
	{
		cin >> x >> y >> t;
		wave(x, y, t, 1);
		wave(x, y, t + 2, -1);
	}
	for (y = 4; y >= -4; y--)
	{
		for (x = -4; x <= 4; x++) 
		{
			if (x == B1 || x == B2) 
			{
				cout << 'X';
				continue;
			}
			i = map[y + 4][x + 4];
			if (i > 0) cout << '*';
			else if (i < 0) cout << 'o';
			else cout << '-';
		}
		cout << endl;
	}
	return 0;
}
