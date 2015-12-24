#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
	unsigned L, R;
	Node *_l, *_r;
	long long Height;

	Node(unsigned l, unsigned r, Node *_l, Node *_r) : L(l), R(r), _l(_l), _r(_r), Height(0) { }
};

int a[40001], b[40001], h[40001], map[80001], res[80001], r[40001];

struct SegmentTree
{
private:
	Node *root;

	Node *build(int l, int r)
	{
		if (l == r - 1) return new Node(l, r, NULL, NULL);
		else return new Node(l, r, build(l, (l + r) / 2), build((l + r) / 2, r));
	}

	void update(unsigned l, unsigned r, Node *n, long long val)
	{
		if (val <= n->Height) return;
		if (l == n->L && r == n->R) n->Height = max(n->Height, val);
		else
		{
			if (n->Height > 0)
			{
				n->_l->Height = n->_r->Height = n->Height;
				n->Height = 0;
			}
			if (r <= n->_l->R) update(l, r, n->_l, val);
			else if (l >= n->_r->L) update(l, r, n->_r, val);
			else update(l, n->_l->R, n->_l, val), update(n->_r->L, r, n->_r, val);
		}
	}

	long long query(unsigned l, unsigned r, Node *n)
	{
		if (n->Height > 0) return n->Height * (map[n->R] - map[n->L]);
		else if (l != r-1)
		{
			if (r <= n->_l->R) return query(l, r, n->_l);
			else if (l >= n->_r->L) return query(l, r, n->_r);
			else return query(l, n->_l->R, n->_l) + query(n->_r->L, r, n->_r);
		}
		return 0;
	}

public:
	SegmentTree(unsigned n) { root = build(1, n); }

	void Update(unsigned l, unsigned r, long long val) { update(l, r, root, val); }

	long long Query(unsigned l, unsigned r) { return query(l, r, root); }
};

bool cmp(const int &a, const int &b) { return h[a] < h[b]; }

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> h[i];
		map[i * 2 - 1] = a[i];
		map[i * 2] = b[i];
	}
	for (int i = 1; i <= n; i++) r[i] = i;
	sort(r + 1, r + 1 + n, cmp);
	sort(map + 1, map + 1 + n * 2);
	int *end = unique(map + 1, map + 1 + 2 * n);
	SegmentTree st(end - map - 1);
	for (int i = 1; i <= n; i++)
	{
		unsigned x = lower_bound(map + 1, end, a[r[i]]) - map, y = lower_bound(map + 1, end, b[r[i]]) - map;
		st.Update(x, y, h[r[i]]);
	}
	cout << st.Query(1, end - map - 1) << endl;
}
