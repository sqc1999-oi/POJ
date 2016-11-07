#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const string H[] =
{
	"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
	"zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};
const string T[] =
{
	"ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk",
	"ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac"
};
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	cout << t << endl;
	while (t--)
	{
		int hd;
		cin >> hd;
		cin.get();
		string hm;
		cin >> hm;
		int hy;
		cin >> hy;
		int totd = hy * 365 + hd + 1;
		for (int i = 0; hm != H[i]; i++)
			totd += 20;
		string tname = T[totd % 20];
		int ty = (totd - 1) / 260, td = totd % 13;
		if (td == 0) td = 13;
		cout << td << ' ' << tname << ' ' << ty << endl;
	}
}
