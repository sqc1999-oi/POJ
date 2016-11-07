#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int r, m, y;
	cin >> r >> m >> y;
	cout << (int)(m*pow(1.0 + r / 100.0, y)) << endl;
}
