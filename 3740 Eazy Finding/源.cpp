#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
struct node
{
	node *u, *d, *l, *r, *c;
	int cnt, row;
};
node *c[301], cache[5000];
int pos;
node *get_node()
{
	return &cache[pos++];
}
void remove(node *x)
{
	x->r->l = x->l;
	x->l->r = x->r;
	for (node *i = x->d; i != x; i = i->d)
		for (node *j = i->r; j != i; j = j->r)
		{
			j->u->d = j->d;
			j->d->u = j->u;
			j->c->cnt--;
		}
}
void resume(node *x)
{
	for (node *i = x->u; i != x; i = i->u)
		for (node *j = i->l; j != i; j = j->l)
		{
			j->c->cnt++;
			j->u->d = j->d->u = j;
		}
	x->l->r = x->r->l = x;
}
bool dfs()
{
	if (c[0]->r == c[0]) return true;
	node *min = NULL;
	for (node *i = c[0]->r; i != c[0]; i = i->r)
		if (min == NULL || i->cnt <= min->cnt)
			min = i;
	remove(min);
	for (node *i = min->d; i != min; i = i->d)
	{
		for (node *j = i->r; j != i; j = j->r)
			remove(j->c);
		if (dfs()) return true;
		for (node *j = i->l; j != i; j = j->l)
			resume(j->c);
	}
	resume(min);
	return false;
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		pos = 0;
		c[0] = get_node();
		for (int i = 1; i <= m; i++)
		{
			c[i] = get_node();
			c[i]->l = c[i - 1];
			c[i - 1]->r = c[i];
			c[i]->u = c[i]->d = c[i];
			c[i]->cnt = 0;
		}
		c[0]->l = c[m];
		c[0]->u = c[0]->d = c[0];
		c[m]->r = c[0];
		for (int i = 1; i <= n; i++)
		{
			node *r = NULL;
			for (int j = 1; j <= m; j++)
			{
				int f;
				char ch;
				do ch = getchar();
				while (!isdigit(ch));
				f = ch - '0';
				if (f)
				{
					c[j]->cnt++;
					node *b = c[j]->u, *t = get_node();
					t->row = i;
					t->c = c[j];
					b->d = t;
					t->u = b;
					t->d = c[j];
					c[j]->u = t;
					if (r == NULL)
					{
						r = t;
						t->l = t->r = t;
					}
					else
					{
						r->l->r = t;
						t->l = r->l;
						r->l = t;
						t->r = r;
					}
				}
			}
		}
		if (dfs()) puts("Yes, I found it");
		else puts("It is impossible");
	}
}
