#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int DAYS_OF_MONTHS[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int hour, min, sec, day, mon, year;
		scanf("%d:%d:%d %d.%d.%d", &hour, &min, &sec, &day, &mon, &year);
		int totSec = hour * 3600 + min * 60 + sec;
		(totSec *= 125) /= 108;
		printf("%d:%d:%d ", totSec / 10000, totSec % 10000 / 100, totSec % 100);
		int totDay = 0;
		if (year != 2000) totDay = 366 + 365 * (year - 1 - 2000) + (year - 1 - 2000) / 4 - (year - 1 - 2000) / 100 + (year - 1 - 2000) / 400;
		bool isLeap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
		for (int j = 1; j < mon; j++) totDay += DAYS_OF_MONTHS[j] + (j == 2 && isLeap);
		totDay += day - 1;
		printf("%d.%d.%d\n", totDay % 100 + 1, totDay % 1000 / 100 + 1, totDay / 1000);
	}
}