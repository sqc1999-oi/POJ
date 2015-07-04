#include <iostream>
#include <algorithm>
using namespace std;
int x[100001];
int main()
{
	ios::sync_with_stdio(false);
	int n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> x[i];
	sort(x + 1, x + 1 + n);
	int l = 0, r = x[n], ans = 0;
	while (l <= r)
	{

	}
}