#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int dis[100001], n, k;

void push(int x, int o, queue<int> &q)
{
	if (x >= 0 && x <= 100000 && dis[x] == -1)
	{
		if (x == k)
		{
			cout << dis[o] + 1;
			exit(0);
		}
		q.push(x);
		dis[x] = dis[o] + 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	memset(dis, 255, sizeof(dis));
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	dis[n] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		push(x + 1, x, q);
		push(x - 1, x, q);
		push(x * 2, x, q);
	}
	cout << 0;
}
