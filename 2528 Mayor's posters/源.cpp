#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node
{
	int L, R, Val;
	bool HasMark;
	Node *LC, *RC;
};

bool a[10001];

struct SegmentTree
{
private:
	Node* root;

	Node* build(int l, int r)
	{
		if (l == r) return new Node{ l,r,0,false,NULL,NULL };
		return new Node{ l,r,0,false,build(l, (l + r) / 2),build((l + r) / 2 + 1, r) };
	}

	void push_down(Node* n)
	{
		if (!n->HasMark) return;
		n->LC->Val = n->RC->Val = n->Val;
		n->LC->HasMark = n->RC->HasMark = true;
		n->HasMark = false;
	}

	void update(int l, int r, int val, Node* n)
	{
		if (n->L == l && n->R == r)
		{
			n->Val = val;
			n->HasMark = true;
		}
		else
		{
			push_down(n);
			if (r <= n->LC->R) update(l, r, val, n->LC);
			else if (l >= n->RC->L) update(l, r, val, n->RC);
			else
			{
				update(l, n->LC->R, val, n->LC);
				update(n->RC->L, r, val, n->RC);
			}
		}
	}

	void query(Node* n)
	{
		if (n->L == n->R) a[n->Val] = true;
		else
		{
			push_down(n);
			query(n->LC);
			query(n->RC);
		}
	}

public:
	SegmentTree(int n)
	{
		root = build(1, n);
	}

	void Update(int l, int r, int val)
	{
		update(l, r, val, root);
	}

	int Query(int n)
	{
		memset(a, 0, sizeof a);
		query(root);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (a[i])
				cnt++;
		return cnt;
	}
} T(20000);

struct
{
	int a, b;
} q[10001];

int map[20001];

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		T.Update(1, 20000, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> q[i].a >> q[i].b;
			map[i] = q[i].a;
			map[i + n] = q[i].b;
		}
		sort(map + 1, map + 1 + 2 * n);
		int* end = unique(map + 1, map + 1 + 2 * n);
		for (int i = 1; i <= n; i++)
			T.Update(lower_bound(map + 1, end, q[i].a) - map, lower_bound(map + 1, end, q[i].b) - map, i);
		cout << T.Query(n) << endl;
	}
}
