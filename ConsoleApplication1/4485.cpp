#include "pch.h"

#define INF 987654321

#define value pair<int, pair<int,int>>

priority_queue < value, vector<value>, greater<value>> que;
int dist[130][130];
int v[130][130];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {  0, 1, 0, -1 };

int n = INF;
bool Inp_Flag;
vector<int> answer;
int Answer = 0;
void dijekstra()
{
	que.push({ v[0][0], {0, 0} });
	dist[0][0] = v[0][0];

	while (!que.empty())
	{
		int _w = que.top().first;
		int _x = que.top().second.first;
		int _y = que.top().second.second;

		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int __x = _x + dx[i];
			int __y = _y + dy[i];

			if (-1 < __x && __x < n && -1 < __y && __y < n)
			{
				int __w = v[__y][__x];

				if(dist[_y][_x] + __w < dist[__y][__x] )
				{
					dist[__y][__x] = __w + dist[_y][_x];
					que.push({ dist[__y][__x], {__x, __y} });
				}
			}
		}
	}
	Answer = dist[n - 1][n - 1];
}

void Input()
{
	cin >> n;
	if (n == 0)
	{
		Inp_Flag = true;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
}

void clear()
{
	for (int i = 0; i < 130; ++i)
	{
		for (int j = 0; j < 130; ++j)
		{
			dist[i][j] = INF;
		}
	}
}

void Solve()
{
	for (int T = 1; ; T++)
	{
		clear();
		Input();
		if (Inp_Flag == true) return;
		dijekstra();

		cout << "Problem " << T << ": " << Answer << endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	Solve();
	return 0;
}