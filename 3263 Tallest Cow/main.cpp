#include <iostream>
#include <algorithm>

struct SegmentTree
{
private:
	struct node
	{
		int L, R, Add, Sum;
		node *_l, *_r;

		node(int L, int R, node *_l, node *_r) : L(L), R(R), _l(_l), _r(_r), Add(0), Sum(0) { }
	};

	node *root;

	node *build(int l, int r)
	{
		if (l == r) return new node(l, r, NULL, NULL);
		else return new node(l, r, build(l, (l + r) / 2), build((l + r) / 2 + 1, r));
	}

	void push_down(node *n)
	{
		n->_l->Add += n->Add;
		n->_l->Sum += n->Add;
		n->_r->Add += n->Add;
		n->_r->Sum += n->Add;
		n->Add = 0;
	}

	void maintain(node *n)
	{
		n->Sum = n->_l->Sum + n->_r->Sum;
	}

	void add(int l, int r, node *n, int val)
	{
		if (l == n->L && r == n->R) n->Add += val, n->Sum += val;
		else
		{
			push_down(n);
			if (r <= n->_l->R) add(l, r, n->_l, val);
			else if (l >= n->_r->L) add(l, r, n->_r, val);
			else add(l, n->_l->R, n->_l, val), add(n->_r->L, r, n->_r, val);
			maintain(n);
		}
	}

	int query(int l, int r, node *n)
	{
		if (l == n->L && r == n->R) return n->Sum;
		else
		{
			push_down(n);
			if (r <= n->_l->R) return query(l, r, n->_l);
			else if (l >= n->_r->L) return query(l, r, n->_r);
			else return query(l, n->_l->R, n->_l) + query(n->_r->L, r, n->_r);
		}
	}

public:
	SegmentTree(int n = 1) { root = build(1, n); }

	void Add(int l, int r, int val) { add(l, r, root, val); }

	int Query(int l, int r) { return query(l, r, root); }
};

using namespace std;
SegmentTree st;
typedef pair<int, int> pii;
pii p[10001];

int main()
{
	ios::sync_with_stdio(false);
	int n, h, r;
	cin >> n >> h >> h >> r;
	st = SegmentTree(n);
	for (int i = 1; i <= r; i++)
	{
		cin >> p[i].first >> p[i].second;
		if (p[i].first > p[i].second) swap(p[i].first, p[i].second);
	}
	sort(p + 1, p + 1 + r);
	pii *end = unique(p + 1, p + 1 + r);
	for (int i = 1; &p[i] != end; i++)
	{
		if (p[i].first >= p[i].second - 1) continue;
		st.Add(p[i].first+1, p[i].second-1, 1);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << h - st.Query(i, i) << endl;
	}
}
