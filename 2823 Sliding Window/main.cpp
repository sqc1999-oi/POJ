#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q1;
priority_queue<pii> q2;
int a[1000001];

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < k; i++)
	{
		q1.push(pii(a[i], i));
		q2.push(pii(a[i], i));
	}
	for (int i = 1; i <= n - k + 1; i++)
	{
		while (!q1.empty() && q1.top().second < i)
			q1.pop();
		q1.push(pii(a[i + k - 1], i + k - 1));
		cout << q1.top().first << ' ';
	}
	cout << endl;
	for (int i = 1; i <= n - k + 1; i++)
	{
		while (!q2.empty() && q2.top().second < i)
			q2.pop();
		q2.push(pii(a[i + k - 1], i + k - 1));
		cout << q2.top().first << ' ';
	}
}
