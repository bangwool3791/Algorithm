#include "pch.h"

#define INF 987654321

long long v[51][51];
priority_queue<pair<int, pair<int,int>>> que;
long long dist[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n = 0;

void dijksta()
{
	que.push({ 0, {0,0} });
	dist[0][0] = 0;
	
	while (!que.empty())
	{
		int w = que.top().first;
		int x = que.top().second.first;
		int y = que.top().second.second;
		que.pop();

		if (dist[y][x] < w)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			int _x = x + dx[i];
			int _y = y + dy[i];
			int _w = 1;

			if (-1 < _x && _x < n && -1 < _y && _y < n)
			{
				if (dist[y][x] + _w < dist[_y][_x] && 0 == v[_y][_x])
				{
					dist[_y][_x] = dist[y][x] + _w;
					que.push({ dist[_y][_x] , {_x, _y} });
				}
				else if (dist[y][x] < dist[_y][_x] && 1 == v[_y][_x])
				{
					dist[_y][_x] = dist[y][x];
					que.push({ dist[_y][_x] , {_x, _y} });
				}

			}
		}
	}
}

void clear()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dist[i][j] = INF;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char a = 0;
			cin >> a;
			v[i][j] = atoi(&a);
		}
	}
	clear();
	dijksta();

	cout << dist[n - 1][n - 1] << endl;
	return 0;
}