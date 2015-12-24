#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define Maxn 132000

//�궨�����ȫ��������
#define lx (x<<1)
#define rx ((x<<1) | 1)
#define MID ((l + r)>>1)

int cover[Maxn << 2];
int XOR[Maxn << 2];
bool vis[Maxn + 5];

void FXOR(int x)
{
	if (cover[x] != -1) cover[x] ^= 1;
	//ע����else
	else XOR[x] ^= 1;
}

void pushDown(int x)
{
	//cover[x] == -1����x�ڵ�ĸ��ǹ����Ѿ�����
	if (cover[x] != -1)
	{
		cover[lx] = cover[rx] = cover[x];
		XOR[lx] = XOR[rx] = 0;//��Ȼ�Ѿ���������Ǿ�����
		cover[x] = -1;
	}
	if (XOR[x])
	{
		FXOR(lx);
		FXOR(rx);
		XOR[x] = 0;
	}
}

void update(int L, int R, char op, int l, int r, int x)
{
	if (L <= l && r <= R)
	{
		if (op == 'U')
		{
			cover[x] = 1;
			XOR[x] = 0;
		}
		//op == 'I'�����������L<=l && r<=R�����Բ���Ҫ����
		else if (op == 'D')
		{
			cover[x] = 0;
			XOR[x] = 0;
		}
		else if (op == 'C') FXOR(x);
		else if (op == 'S') FXOR(x);
		return;
	}
	pushDown(x);
	if (L <= MID) update(L, R, op, l, MID, lx);
	else if (op == 'I' || op == 'C') cover[lx] = XOR[lx] = 0;
	if (MID < R) update(L, R, op, MID + 1, r, rx);
	else if (op == 'I' || op == 'C') cover[rx] = XOR[rx] = 0;
}

//ֻ�ʺ���һ�β�ѯ
void query(int l, int r, int x)
{
	if (cover[x] == 1)
	{
		for (int i = l; i <= r; i++) vis[i] = true;
		return;
	}
	else if (cover[x] == 0) return;
	if (l == r) return;
	pushDown(x);
	query(l, MID, lx);
	query(MID + 1, r, rx);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int a, b;
	char op, lchar, rchar;
	XOR[1] = cover[1] = 0;
	while (scanf("%c %c%d,%d%c\n", &op, &lchar, &a, &b, &rchar) != EOF)
	{
		a <<= 1;
		b <<= 1;
		if (lchar == '(') a++;
		if (rchar == ')') b--;
		update(a, b, op, 0, Maxn, 1);
	}
	query(0, Maxn, 1);
	int s = -1, e;
	bool flag = false;
	for (int i = 0; i <= Maxn; i++)
	{
		if (vis[i] == 1)
		{
			if (s == -1) s = i;
			e = i;
		}
		else
		{
			if (s != -1)
			{
				if (flag) printf(" ");
				printf("%c%d,%d%c", s & 1 ? '(' : '[', s >> 1, (e + 1) >> 1, e & 1 ? ')' : ']');
				s = -1;
				flag = true;
			}
		}
	}
	if (!flag) printf("empty set");
	puts("");
	return 0;
}
