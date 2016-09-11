#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int A, B, C;
struct Calf
{
	int H, W, V;
	void CalcV() { V = A*H + B*W; }
	bool operator < (const Calf &a) const
	{
		return V < a.V;
	}
};
bool cmp(const Calf &a, const Calf &b)
{
	return a.H > b.H;
}
Calf a[1001];
int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N >> A >> B >> C;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i].H >> a[i].W;
		a[i].CalcV();
	}
	sort(a + 1, a + 1 + N, cmp);
	priority_queue<Calf> q;
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		while (!q.empty()) q.pop();
		Calf cu = a[i];
		for (int j = 1; j <= N; j++)
		{
			if (a[j].V <= cu.V + C)
			{
				cu.H = min(cu.H, a[j].H);
				cu.CalcV();
				if (a[j].W >= cu.W) q.push(a[j]);
				while (!q.empty() && q.top().V > cu.V + C) q.pop();
				ans = max(ans, (int)q.size());
			}
		}
	}
	cout << ans << endl;
}
