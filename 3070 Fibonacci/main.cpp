#include <iostream>
#include <algorithm>
using namespace std;
struct Matrix
{
	int n, m;
	int data[2][2];
};
Matrix operator *(const Matrix &a, const Matrix &b)
{
	Matrix c;
	c.n = a.n;
	c.m = b.m;
	for (int i = 0; i < c.n; i++)
		for (int j = 0; j < c.m; j++)
		{
			c.data[i][j] = 0;
			for (int k = 0; k < a.m; k++)
				(c.data[i][j] += (a.data[i][k] * b.data[k][j]) % 10000) %= 10000;
		}
	return c;
}
Matrix Pow(Matrix a, int b)
{
	if (b == 1) return a;
	Matrix res = a;
	for (--b; b; b >>= 1, a = a * a)
		if (b & 1)
			res = res * a;
	return res;
}
Matrix a, b;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	a.n = 2;
	a.m = 2;
	a.data[0][0] = a.data[0][1] = a.data[1][0] = 1;
	a.data[1][1] = 0;
	while (cin >> n&&n != -1)
	{
		if (n == 0)
		{
			cout << 0 << endl;;
			continue;
		}
		b.data[0][0] = 1;
		b.data[0][1] = 0;
		b.n = 2;
		b.m = 1;
		cout << (Pow(a, n)*b).data[1][0] << endl;
	}
}
