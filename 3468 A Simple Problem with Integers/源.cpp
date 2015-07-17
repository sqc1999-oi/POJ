#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int L, R;
	long long Sum, Add;
	Node *LC, *RC;
};

struct SegmentTree
{
private:
	Node* root;

	Node* build(int l, int r)
	{
		if (l == r) return new Node{ l,r,0,0,NULL,NULL };
		return new Node{ l,r,0,0,build(l, (l + r) / 2),build((l + r) / 2 + 1, r) };
	}

	void push_down(Node* n)
	{
      	n->LC->Add += n->Add;
		n->RC->Add += n->Add;
		n->LC->Sum += n->Add * (n->LC->R - n->LC->L + 1);
		n->RC->Sum += n->Add * (n->RC->R - n->RC->L + 1);
		n->Add = 0;
	}

	void add(int l, int r, long long val, Node* n)
	{
		if (n->L == l && n->R == r)
		{
			n->Add += val;
			n->Sum += val * (r - l + 1);
		}
		else
		{
			push_down(n);
			if (r <= n->LC->R) add(l, r, val, n->LC);
			else if (l >= n->RC->L) add(l, r, val, n->RC);
			else
			{
				add(l, n->LC->R, val, n->LC);
				add(n->RC->L, r, val, n->RC);
			}
			n->Sum = n->LC->Sum + n->RC->Sum;
		}
	}

	long long query(int l, int r, Node* n)
	{
		if (n->L == l && n->R == r) return n->Sum;
		push_down(n);
		if (r <= n->LC->R) return query(l, r, n->LC);
		if (l >= n->RC->L) return query(l, r, n->RC);
		return query(l, n->LC->R, n->LC) + query(n->RC->L, r, n->RC);
	}

public:
	SegmentTree(int n)
	{
		root = build(1, n);
	}

	void Add(int l, int r, long long val)
	{
		add(l, r, val, root);
	}

	long long Query(int l, int r)
	{
		return query(l, r, root);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	SegmentTree T(n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		T.Add(i, i, x);
	}
	for (int i = 1; i <= q; i++)
	{
		char ch;
		cin >> ch;
		if (ch == 'Q')
		{
			int a, b;
			cin >> a >> b;
			cout << T.Query(a, b) << endl;
		}
		else if (ch == 'C')
		{
			int a, b, c;
			cin >> a >> b >> c;
			T.Add(a, b, c);
		}
	}
}