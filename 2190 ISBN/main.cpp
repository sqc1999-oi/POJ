#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;
bool check(int *num)
{
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		sum += num[i] * (11 - i);
	}
	return sum % 11 == 0;
}
int main()
{
	int num[11], pos;
	for (int i = 1; i <= 10; i++)
	{
		char ch;
		cin >> ch;
		if (isdigit(ch)) num[i] = ch - '0';
		else if (ch == 'X')
		{
			if (i == 10) num[i] = 10;
			else
			{
				cout << -1 << endl;
				return 0;
			}
		}
		else if (ch == '?') pos = i;
		else
		{
			cout << -1 << endl;
			return 0;
		}
	}
	for (num[pos] = 0; num[pos] <= (pos == 10 ? 10 : 9); num[pos]++)
	{
		if (check(num))
		{
			(num[pos] == 10 ? (cout << 'X') : (cout << num[pos])) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
