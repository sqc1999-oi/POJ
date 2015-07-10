#include <iostream>
#include <algorithm>
using namespace std;
int p[20001];

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	ios::sync_with_stdio(false);
}
