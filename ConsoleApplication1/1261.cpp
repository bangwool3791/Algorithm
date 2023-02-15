#include "pch.h"

#define INF 987654321

int n = 0, m = 0;

#define value pair<int, pair<int, int>>
priority_queue<value, vector<value>, greater<value>> que;
vector<vector<int>> v;

int dist[101][101];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {  0, 1, 0, -1 };

int nextCount = 0;

void dijkstra(int x, int y)
{
	que.push(make_pair(0, make_pair(x, y)));
	dist[y][x] = 0;

	while (!que.empty())
	{
		int _w = que.top().first;
		int _x = que.top().second.first;
		int _y = que.top().second.second;
		que.pop();

		if (dist[_y][_x] < _w)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			int __x = _x + dx[i];
			int __y = _y + dy[i];

			if (-1 < __x && __x < m && -1 < __y && __y < n)
			{
				if (0 == v[__y][__x])
				{
					nextCount = dist[_y][_x];
				}
				else if (1 == v[__y][__x])
				{
					nextCount = dist[_y][_x] + 1;
				}

				if (dist[__y][__x] > nextCount)
				{
					dist[__y][__x] = nextCount;
					que.push(make_pair(nextCount, make_pair(__x, __y)));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			dist[i][j] = INF;
		}
	}

	cin >> m >> n;

	v.resize(n + 1, vector<int>());

	for (int i = 0; i < n + 1; ++i)
	{
		v[i].resize(m + 1);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char data = 0;
			cin >> data;
			v[i][j] = atoi(&data);
		}
	}

	dijkstra(0, 0);

	cout << dist[n - 1][m - 1] << endl;

	return 0;
}