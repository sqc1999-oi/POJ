#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct node
{
	node *u, *d, *l, *r, *c;
	int cnt, row;
} *c[400], cache[300000];
struct row_info
{
	int r, c, x;
} info[730];
char s[100];
int pos, rc, a[10][10];
vector<int> ans;
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
		ans.push_back(i->row);
		for (node *j = i->r; j != i; j = j->r)
			remove(j->c);
		if (dfs()) return true;
		for (node *j = i->l; j != i; j = j->l)
			resume(j->c);
		ans.pop_back();
	}
	resume(min);
	return false;
}
void add_cell(node *&r, int i, int j)
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
void add_row(int i, int j, int x)
{
	rc++;
	info[rc].r = i;
	info[rc].c = j;
	info[rc].x = x;
	i--;
	j--;
	x--;
	node *t = NULL;
	add_cell(t, rc, 1 + i * 9 + j);
	add_cell(t, rc, 82 + i * 9 + x);
	add_cell(t, rc, 163 + j * 9 + x);
	add_cell(t, rc, 244 + (i / 3 * 3 + j / 3) * 9 + x);
}
int main()
{
	while (true)
	{
		scanf("%s", s);
		if (strcmp(s, "end") == 0) break;
		pos = rc = 0;
		c[0] = get_node();
		for (int i = 1; i <= 324; i++)
		{
			c[i] = get_node();
			c[i]->l = c[i - 1];
			c[i - 1]->r = c[i];
			c[i]->u = c[i]->d = c[i];
			c[i]->cnt = 0;
		}
		c[0]->l = c[324];
		c[0]->u = c[0]->d = c[0];
		c[324]->r = c[0];
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
			{
				int x = (i - 1) * 9 + j - 1;
				if (s[x] != '.') add_row(i, j, s[x] - '0');
				else for (int k = 1; k <= 9; k++) add_row(i, j, k);
			}
		ans.clear();
		if (dfs())
		{
			for (int i = 0; i < ans.size(); i++)
				a[info[ans[i]].r][info[ans[i]].c] = info[ans[i]].x;
			for (int i = 1; i <= 9; i++)
				for (int j = 1; j <= 9; j++)
					printf("%d", a[i][j]);
			puts("");
		}
	}
}
