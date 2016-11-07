#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
typedef pair<int, int> pii;
int a[101];
bool vis[70000];
const int INF = 0x7fffffff;
void print(int x, int b)
{
	stack<int> s;
	for (int i = 1; i <= b; i++)
	{
		s.push(x % 2);
		x /= 2;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}
int caldiff(int x, int y, int b)
{
	int cnt = 0;
	for (int i = 1; i <= b; i++)
	{
		cnt += x % 2 != y % 2;
		x /= 2;
		y /= 2;
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	int b, e;
	queue<pii> q;
	cin >> b >> e;
	for (int i = 0; i <= e; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			char ch;
			cin >> ch;
			(a[i] *= 2) += ch - '0';
		}
		if (i > 0) q.push(pii{ a[i],0 });
	}
	int diff, step, val;
	diff = step = val = INF;
	while (!q.empty())
	{
		pii x = q.front();
		q.pop();
		for (int i = 1; i <= e; i++)
		{
			int tmp = a[i] ^ x.first;
			if (!vis[tmp])
			{
				vis[tmp] = true;
				if (caldiff(tmp, a[0], b) < diff || (caldiff(tmp, a[0], b) == diff && (x.second + 1 < step || (step == x.second + 1 && tmp < val))))
				{
					diff = caldiff(tmp, a[0], b);
					step = x.second + 1;
					val = tmp;
				}
				q.push(pii{ tmp,x.second + 1 });
			}
		}
	}
	cout << step << endl;
	print(val, b);
}
