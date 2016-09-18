#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;
char ch[10000][75];
int tmp[10001];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a / gcd(a, b)*b; }
int main()
{
	ios::sync_with_stdio(false);
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			while (!isupper(ch[i][j])) cin >> ch[i][j];
		}
	}
	int row = 1;
	for (int i = 0; i < r; i++)
	{
		tmp[0] = 0;
		tmp[1] = 0;
		for (int j = 1; j < c; j++)
		{
			int k = tmp[j];
			while (k&&ch[i][j] != ch[i][k]) k = tmp[k];
			tmp[j + 1] = ch[i][j] == ch[i][k] ? k + 1 : 0;
		}
		row = lcm(row, c - tmp[c]);
		if (row > c)
		{
			row = c;
			break;
		}
	}
	int col = 1;
	for (int i = 0; i < c; i++)
	{
		tmp[0] = 0;
		tmp[1] = 0;
		for (int j = 1; j < r; j++)
		{
			int k = tmp[j];
			while (k&&ch[j][i] != ch[k][i]) k = tmp[k];
			tmp[j + 1] = ch[j][i] == ch[k][i] ? k + 1 : 0;
		}
		col = lcm(col, r - tmp[r]);
		if (col > r)
		{
			col = r;
			break;
		}
	}
	cout << row*col << endl;
}
