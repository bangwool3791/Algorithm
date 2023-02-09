#include "pch.h"


int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;
int c = 0;
int origin[8][8];
int copy_map[8][8];

void MapCopy(int(*a)[8], int(*b)[8])
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			a[i][j] = b[i][j];
		}
	}
}

void bfs()
{
	queue<pair<int, int>> que;

	int map[8][8];

	MapCopy(map, copy_map);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (2 == map[i][j])
			{
				que.push(make_pair(i, j));
			}
		}
	}

	while (!que.empty())
	{
		pair<int, int> p = que.front();
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int _x = p.second + dx[i];
			int _y = p.first +dy[i];

			if (-1 < _x && _x < m && -1 < _y && _y < n)
			{
				if (0 == map[_y][_x])
				{
					map[_y][_x] = 2;
					que.push(make_pair(_y, _x));
				}
			}
			
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (0 == map[i][j])
				++cnt;
		}
	}

	c = max(cnt, c);
}

void block(int idx)
{
	if (3 == idx)
	{
		bfs();
		return;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (0 == copy_map[i][j])
				{
					copy_map[i][j] = 1;
					block(idx + 1);
					copy_map[i][j] = 0;
				}
			}
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int data = 0;
			cin >> data;
			origin[i][j] = data;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			MapCopy(copy_map, origin);
			if (0 == copy_map[i][j])
			{
				copy_map[i][j] = 1;
				block(1);
				copy_map[i][j] = 0;
			}
		}
	}

	cout << c << endl;
	return 0;
}
