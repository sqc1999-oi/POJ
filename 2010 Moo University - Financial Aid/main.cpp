#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct Calf
{
	int Score, Aid;

	bool operator<(const Calf a) const
	{
		return Aid < a.Aid;
	}
} a[100001];

int lower[100001], upper[100001];

bool cmp(const Calf &a, const Calf &b)
{
	return a.Score < b.Score;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, c, f;
	cin >> n >> c >> f;
	int half = n / 2;
	for (int i = 1; i <= c; i++)
	{
		cin >> a[i].Score >> a[i].Aid;
	}
	sort(a + 1, a + 1 + c, cmp);
	priority_queue<int> q;
	int sum = 0;
	for (int i = 1; i <= half; i++)
	{
		q.push(a[i].Aid);
		sum += a[i].Aid;
	}
	lower[half + 1] = sum;
	for (int i = half + 1; i < c; i++)
	{
		if (a[i].Aid < q.top())
		{
			(sum -= q.top()) += a[i].Aid;
			q.pop();
			q.push(a[i].Aid);
		}
		lower[i + 1] = sum;
	}
	while (!q.empty()) q.pop();
	sum = 0;
	for (int i = c; i > c - half; i--)
	{
		q.push(a[i].Aid);
		sum += a[i].Aid;
	}
	upper[c - half] = sum;
	for (int i = c - half; i > 1; i--)
	{
		if (a[i].Aid < q.top())
		{
			(sum -= q.top()) += a[i].Aid;
			q.pop();
			q.push(a[i].Aid);
		}
		upper[i - 1] = sum;
	}
	for (int i = c - half; i > half; i--)
	{
		if (lower[i] + upper[i] + a[i].Aid <= f)
		{
			cout << a[i].Score;
			return 0;
		}
	}
	cout << -1;
}
