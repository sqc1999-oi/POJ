#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int a, i;
	bool operator < (const node &a) const { return this->a < a.a; }
};
priority_queue<node> q;
int b[50001];
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		q.push(node{ x,i });
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 1; i <= k; i++)
	{
		if (b[ans] <= b[q.top().i]) ans = q.top().i;
		q.pop();
	}
	cout << ans << endl;
}
