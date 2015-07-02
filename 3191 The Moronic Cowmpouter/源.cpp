#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	stack<int> s;
	while (n != 1)
	{
		if (abs(n) % 2 != 0) n--, s.push(1);
		else s.push(0);
		n /= (-2);
	}
	cout << 1;
	while (!s.empty()) cout << s.top(), s.pop();
	cout << endl;
}