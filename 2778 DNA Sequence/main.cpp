#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <cassert>
using namespace std;
const int M = 1e5;
struct node
{
	int id;
	node *link[4], *f;
};
struct matrix
{
	int **d, n, m;
	matrix(int n, int m)
	{
		this->n = n;
		this->m = m;
		d = new int *[n + 1];
		for (int i = 1; i <= n; i++)
		{
			d[i] = new int[m + 1];
			for (int j = 1; j <= m; j++)
				d[i][j] = 0;
		}
	}
	matrix(const matrix &a) :n(a.n), m(a.m)
	{
		d = new int *[n + 1];
		for (int i = 1; i <= n; i++)
		{
			d[i] = new int[m + 1];
			for (int j = 1; j <= m; j++)
				d[i][j] = a[i][j];
		}
	}
	matrix operator =(const matrix &a)
	{
		assert(n == a.n && m == a.m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				d[i][j] = a[i][j];
		return *this;
	}
	int *operator [](int x) const
	{
		assert(x <= n);
		return d[x];
	}
	matrix operator *(const matrix &a) const
	{
		assert(m == a.n);
		matrix res(a.n, a.m);
		for (int k = 1; k <= m; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					res[i][j] = (res[i][j] + (long long)d[i][k] * a[k][j]) % M;
		return res;
	}
	matrix operator ^(long long k) const
	{
		assert(n == m);
		matrix a(*this), res(n, m);
		for (int i = 1; i <= n; i++)
			res[i][i] = 1;
		for (; k; k >>= 1, a = a*a)
			if (k & 1) res = res*a;
		return res;
	}
	void display()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				cout << d[i][j] << ' ';
			cout << endl;
		}
		cout << endl;
	}
};
bool flag[1000];
int get_id(char ch)
{
	switch (ch)
	{
	case 'A': return 0;
	case 'C': return 1;
	case 'T': return 2;
	case 'G': return 3;
	default: assert(false);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int m;
	long long n;
	cin >> m >> n;
	node *r = new node();
	r->f = r;
	r->id = 1;
	int cnt = 1;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		node *cu = r;
		for (int i = 0; i < s.length(); i++)
		{
			node *&x = cu->link[get_id(s[i])];
			if (!x)
			{
				x = new node();
				x->id = ++cnt;
			}
			cu = x;
		}
		flag[cu->id] = true;
	}
	queue<node*> q;
	matrix a(1, cnt), b(cnt, cnt);
	for (int i = 0; i < 4; i++)
	{
		node *&x = r->link[i];
		if (x)
		{
			q.push(x);
			x->f = r;
		}
		else x = r;
		if (!flag[x->id])
			b[1][x->id]++;
	}
	while (!q.empty())
	{
		node *u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			node *&v = u->link[i];
			if (v)
			{
				q.push(v);
				v->f = u->f->link[i];
				flag[v->id] |= flag[v->f->id];
			}
			else v = u->f->link[i];
			if (!flag[u->id] && !flag[v->id])
				b[u->id][v->id]++;
		}
	}
	a[1][1] = 1;
	matrix c = a*(b^n);
	int ans = 0;
	for (int i = 1; i <= c.m; i++)
		ans = (ans + c[1][i]) % M;
	cout << ans;
}
