#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[50001];
bool cmp(const int &a, const int &b) { return abs(a) < abs(b); }
int main()
{
	ios::sync_with_stdio(false);
	int T, n;
	cin >> T >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + 1 + n, cmp);
	for (int i = 1, t = 0; i <= n; i++)
	{
		t += abs(a[i] - a[i - 1]);
		if (t > T)
		{
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << n << endl;
}
