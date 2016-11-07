#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	int board[21][21];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			board[j][i] = (s - 1) % 9 + 1;
			s++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			(i > j ? cout << ' ' : cout << board[i][j]) << ' ';
		}
		cout << endl;
	}
}
