#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
struct SegmentTree
{
private:
	struct node
	{
		int L, R, Min;
		node *_l, *_r;
		node(const int &L, const int &R, node *_l, node *_r) :L(L), R(R), _l(_l), _r(_r), Min(INF) {}
	};
	node *root;
	node *build(const int &l, const int &r)
	{
		if (l == r) return new node(l, r, NULL, NULL);
		else return new node(l, r, build(l, (l + r) / 2), build((l + r) / 2 + 1, r));
	}
	void update(const int &pos, const int &val, node *n)
	{
		n->Min = min(n->Min, val);
		if (n->L == n->R) return;
		if (pos <= n->_l->R) update(pos, val, n->_l);
		else update(pos, val, n->_r);
	}
	int query(const int &l, const int &r, node *n)
	{
		if (l == n->L && r == n->R) return n->Min;
		else if (r <= n->_l->R) return query(l, r, n->_l);
		else if (l >= n->_r->L) return query(l, r, n->_r);
		else return min(query(l, n->_l->R, n->_l), query(n->_r->L, r, n->_r));
	}
public:
	inline SegmentTree(const int &l, const int &r) { root = build(l, r); }
	inline SegmentTree() {}
	inline void Update(const int &pos, const int &val) { update(pos, val, root); }
	inline int Query(const int &l, const int &r) { return query(l, r, root); }
};
struct cow
{
	int t1, t2, s;
	bool operator<(const cow &a) const
	{
		return t2 < a.t2;
	}
} a[10001];
int f[86400];
int main()
{
	ios::sync_with_stdio(false);
	int n, m, e;
	cin >> n >> m >> e;
	SegmentTree st(m, e);
	for (int i = 1; i <= n; i++) cin >> a[i].t1 >> a[i].t2 >> a[i].s;
	sort(a + 1, a + 1 + n);
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
	{
		cow &c = a[i];
		int tmp = f[c.t2];
		f[c.t2] = min(f[c.t2], c.t1 == m ? c.s : (st.Query(c.t1 - 1, c.t2 - 1) + c.s));
		if (tmp != f[c.t2]) st.Update(c.t2, f[c.t2]);
	}
	cout << (f[e] < INF ? f[e] : -1);
}