#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdlib>
using namespace std;
struct node
{
	int a, b, cnt;
};
bool inq[201][20001];
int p;
queue<node> q;
inline void push(int a, int b, int cnt)
{
	if (a == p || b == p)
	{
		cout << cnt << endl;
		exit(0);
	}
	if (a > b)
	{
		int t = a;
		a = b;
		b = t;
	}
	if (a <= 200 && b <= 20000 && !inq[a][b])
	{
		inq[a][b] = true;
		node n;
		n.a = a, n.b = b, n.cnt = cnt;
		q.push(n);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> p;
	node n;
	n.a = 0;
	n.b = 1;
	n.cnt = 0;
	q.push(n);
	inq[0][1] = true;
	while (true)
	{
		node n = q.front();
		q.pop();
		inq[n.a][n.b] = false;
		int a, b, cnt = n.cnt + 1;
		if (n.a == 0)
		{
			a = 0, b = n.b + n.b;
			push(a, b, cnt);
			a = n.b, b = n.b + n.b;
			push(a, b, cnt);
		}
		else
		{
			a = n.a + n.b, b = n.b;
			push(a, b, cnt);
			a = n.a, b = n.a + n.b;
			push(a, b, cnt);
			a = n.a + n.a, b = n.b;
			push(a, b, cnt);
			a = n.a, b = n.a + n.a;
			push(a, b, cnt);
			a = n.b + n.b, b = n.b;
			push(a, b, cnt);
			a = n.a, b = n.b + n.b;
			push(a, b, cnt);
			a = n.b - n.a, b = n.b;
			push(a, b, cnt);
			a = n.a, b = n.b - n.a;
			push(a, b, cnt);
		}
	}
}