#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.size(); i++)
	{
		if (islower(s2[i]))
		{
			s2[i] = s1[s2[i] - 'a'];
		}
		else if (isupper(s2[i]))
		{
			s2[i] = s1[s2[i] - 'A'] - 'a' + 'A';
		}
	}
	cout << s2 << endl;
}