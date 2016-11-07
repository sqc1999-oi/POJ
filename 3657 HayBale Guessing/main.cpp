#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c, x;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + c - '0';
	return x;
}

const int N = 1000000 + 19;

struct Event
{
	int L, R, x;

	bool operator <(const Event& B) const
	{
		return x > B.x;
	}
} A[N], B[N];

int Fa[N], n, m, L, R, res;

int Getf(int x)
{
	static int S[N];
	int k = 0;
	while (Fa[x] != x) S[++k] = x , x = Fa[x];
	while (k) Fa[S[k--]] = x;
	return x;
}

bool Check(int k)
{
	For(i, 1, k + 1) B[i] = A[i];
	sort(B + 1, B + k + 1);
	For(i, 1, n + 2) Fa[i] = i;
	for (int i = 1; i <= k;)
	{
		int L = 0, R = n + 1, tL = n + 1, tR = 0, x = B[i].x;
		while (i <= k && B[i].x == x)
			L = max(L, B[i].L) , R = min(R, B[i].R) ,
				tL = min(tL, B[i].L) , tR = max(tR, B[i].R) , i++;
		if (Getf(L) > R) return 0;
		for (int j = Getf(tL); j <= tR; j = Getf(j + 1)) Fa[j] = j + 1;
	}
	return 1;
}

int main()
{
	n = IN() , m = IN();
	For(i, 1, m + 1) A[i] = Event{ IN(), IN(), IN() };
	L = 1 , R = m;
	while (L <= R)
		if (Check(Mid)) res = Mid , L = Mid + 1; else R = Mid - 1;
	printf("%d\n", res == m ? 0 : res + 1);
}
