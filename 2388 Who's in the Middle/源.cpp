#include<iostream>
#include<algorithm>
using namespace std;
int a[10001];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	cout << a[n / 2 + 1] << endl;
}