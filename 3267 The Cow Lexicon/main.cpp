#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string dic[601];
int f[302];
int main()
{
	ios::sync_with_stdio(false);
	int w, l;
	cin >> w >> l;
	string msg;
	msg = msg.substr(0, l);
	cin >> msg;
	for (int i = 1; i <= w; i++) cin >> dic[i];
	for (int i = l - 1; i >= 0; i--)
	{
		f[i] = f[i + 1] + 1;
		for (int j = 1; j <= w; j++)
		{
			if (dic[j].length() <= l - i&&dic[j][0] == msg[i])
			{
				int msgpos = i, dicpos = 0;
				while (msgpos < l)
				{
					if (dic[j][dicpos] == msg[msgpos]) dicpos++;
					msgpos++;
					if (dicpos == dic[j].length())
					{
						f[i] = min(f[i], f[msgpos] + msgpos - i - dicpos);
					}
				}
			}
		}
	}
	cout << f[0];
}
