#include<algorithm>
#include<cctype>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
	vector<int> a, b;
	char ch = getchar();
	do { a.push_back(ch - '0'); ch = getchar(); } while (isdigit(ch));
	do { ch = getchar(); } while (!isdigit(ch));
	do { b.push_back(ch - '0'); ch = getchar(); } while (isdigit(ch));
	int ans = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			ans += a[i] * b[j];
		}
	}
	printf("%d", ans);
}
