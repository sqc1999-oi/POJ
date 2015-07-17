#include <iostream>
#include <algorithm>
using namespace std;
const int ID[][4] = { { 0,1,2,3 },{ 4,5,6,7 },{ 8,9,10,11 },{ 12,13,14,15 } };
const int XOR[] = { 19, 39, 78, 140, 305, 626, 1252, 2248, 4880, 10016, 20032, 35968, 12544, 29184, 58368, 51200 };

int main()
{
	ios::sync_with_stdio(false);
	int s = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char ch;
			cin >> ch;
			if (ch == 'b') s |= 1 << ID[i][j];
		}
	}
	int ans = 0x7fffffff;
	for (int i = 0; i < 1 << 16; i++)
	{
		int tmp = s, cnt = 0;
		for (int j = 0; j < 16; j++)
		{
			if (i & 1 << j)
			{
				tmp ^= XOR[j];
				cnt++;
			}
		}
		if (tmp == 0 || tmp == (1 << 16) - 1)
		{
			ans = min(ans, cnt);
		}
	}
	if (ans == 0x7fffffff) cout << "Impossible" << endl;
	else cout << ans << endl;
}