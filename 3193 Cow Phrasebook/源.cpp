#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
string a[1001];
int sizea[1001];
int main()
{
	ios::sync_with_stdio(false);
	int m, n, cnt = 0;
	cin >> m >> n;
	cin.get();
	for (int i = 1; i <= m; i++)
	{
		getline(cin, a[i]);
		sizea[i] = a[i].size();
	}
	for (int i = 1; i <= n; i++)
	{
		string s;
		getline(cin, s);
		int size = s.size();
		for (int j = 1; j <= m; j++)
		{
			bool match = false;
			if (size <= sizea[j])
			{
				int k = 0;
				while (k < size && s[k] == a[j][k]) k++;
				if (k == size)
				{
					cnt++;
					match = true;
				}
			}
			if (match) break;
		}
	}
	cout << cnt;
}