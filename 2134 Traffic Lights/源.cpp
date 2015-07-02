#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct light { int tg, tr, color, tc; } li[200];
struct con { int pos, speed, time; };
int getcolor(con c)
{
	light &l = li[c.pos];
	int t = (l.tc + c.time) % (l.tg + l.tr);
	return (l.color == 1 ? (t < l.tr) : (t >= l.tg)) ? 1 : 2;
}
bool vis[500][500][500];
int n, l;
void push(con c, queue<con> &q)
{
	if (c.pos > l || c.speed < 0) return;
	if (vis[c.pos][c.speed][c.time]) return;
	vis[c.pos][c.speed][c.time] = true;
	q.push(c);
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> l >> n;
	for (int i = 1; i <= n; i++)
	{
		int p;
		cin >> p;
		cin >> li[p].tg >> li[p].tr;
		char ch;
		do cin >> ch; while (ch != 'R'&&ch != 'G');
		li[p].color = ch == 'R' ? 1 : 2;
		cin >> li[p].tc;
	}
	queue<con> q;
	push(con{ 0,0,0 }, q);
	while (!q.empty())
	{
		con c = q.front();
		q.pop();
		if (c.pos == l)
		{
			if (c.speed == 1)
			{
				cout << c.time << endl;
				break;
			}
			else continue;
		}
		if (li[c.pos].color != 0 && getcolor(c) == 1 && c.speed != 0) continue;
		bool b = false;
		for (int i = c.pos + 1; i < c.pos + c.speed; i++)
		{
			if (li[i].color != 0 && getcolor(con{ i,c.speed,c.time }) == 1)
			{
				b = true;
				break;
			}
		}
		if (b) continue;
		push(con{ c.pos + c.speed,c.speed - 1,c.time + 1 }, q);
		push(con{ c.pos + c.speed,c.speed,c.time + 1 }, q);
		push(con{ c.pos + c.speed,c.speed + 1,c.time + 1 }, q);
	}
}