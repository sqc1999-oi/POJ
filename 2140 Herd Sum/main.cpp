#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int l = 0, r = 1, cnt = 0, sum = 0;
	while (l < n)
	{
		sum += r++;
		if (sum == n) cnt++;
		while (sum > n)
		{
			sum -= ++l;
			if (sum == n) cnt++;
		}
	}
	cout << cnt << endl;
}
