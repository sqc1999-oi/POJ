#include<iostream>
#include<string>
using namespace std;
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		if (month < 3)
		{
			year -= 1;
			month += 12;
		}
		const string D[7] = { "sunday","monday","tuesday","wednesday","thursday","friday","saturday" };
		int c = int(year / 100), y = year - 100 * c;
		int w = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (month + 1) / 10) + day - 1;
		w = (w % 7 + 7) % 7;
		cout << D[w] << endl;
	}
}