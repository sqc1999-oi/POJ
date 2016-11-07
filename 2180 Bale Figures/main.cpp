#include <iostream>
#include <algorithm>
using namespace std;
bool map[53][53][27];
struct bale { int x, y, z; } pos[25001];
const bale X[] = { bale{1,0,0},bale{-1,0,0},bale{0,1,0},bale{0,-1,0},bale{0,0,1},bale{0,0,-1} };
int main()
{
	ios::sync_with_stdio(false);
	int n, ans = 5;
	cin >> n;
	map[26][26][0] = true;
	pos[1] = bale{ 26,26,0 };
	for (int i = 2; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		pos[i] = pos[a];
		switch (c)
		{
		case 'L':
			pos[i].x--;
			break;
		case 'R':
			pos[i].x++;
			break;
		case 'F':
			pos[i].y--;
			break;
		case 'B':
			pos[i].y++;
			break;
		case 'O':
			pos[i].z++;
			break;
		case 'U':
			pos[i].z--;
			break;
		}
		if (pos[i].z < 0 || map[pos[i].x][pos[i].y][pos[i].z])
		{ 
			cout << -1;
			return 0;
		}
		else
		{
			map[pos[i].x][pos[i].y][pos[i].z] = true;
			ans += 6;
			for (int j = 0; j < 6; j++)
			{
				bale tmp = pos[i];
				tmp.x += X[j].x;
				tmp.y += X[j].y;
				tmp.z += X[j].z;
				if (tmp.x >= 0 && tmp.x <= 52 && tmp.y >= 0 && tmp.y <= 52 && tmp.z >= 0 && tmp.z <= 26 && map[tmp.x][tmp.y][tmp.z]) ans -= 2;
			}
			if (pos[i].z == 0) ans--;
		}
	}
	cout << ans;
}
