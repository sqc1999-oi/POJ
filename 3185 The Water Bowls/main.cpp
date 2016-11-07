#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void flip(bool *b, bool *e)
{
	for (bool *x = b; x != e; x++)
	{
		*x = !*x;
	}
}
int main()
{
	bool a[20];
	for (int i = 0; i < 20; i++)
	{
		cin >> a[i];
	}
	bool tmp[20];
	memcpy(tmp, a, sizeof(a));
	int cnt1 = 0;
	for (int i = 0; i < 19; i++)
	{
		if (tmp[i])
		{
			cnt1++;
			flip(&tmp[i], &tmp[min(i + 2, 19) + 1]);
		}
	}
	int cnt2 = 0;
	memcpy(tmp, a, sizeof(a));
	for (int i = 19; i > 0; i--)
	{
		if (tmp[i])
		{
			cnt2++;
			flip(&tmp[max(0, i - 2)], &tmp[i] + 1);
		}
	}
	cout << min(cnt1, cnt2) << endl;
}
