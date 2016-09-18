#include<iostream>
#include<algorithm>
using namespace std;
int a[20001];
bool cmp(int a, int b) { return a > b; }
int main()
{
	ios::sync_with_stdio(false);
	int n, b;
	cin >> n >> b;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	int sum = 0, i = 0;
	while (sum < b) sum += a[++i];
	cout << i << endl;
}
