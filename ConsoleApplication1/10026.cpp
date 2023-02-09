#include "pch.h"

vector<char> vec[101];

bool bCheck[101][101];
int dx[4] = { 1,  0, -1, 0 };
int dy[4] = { 0, -1, -0, 1 };

#define R 'R'
#define G 'G'
#define B 'B'

int n = 0;

void bfs(int x, int y, char value)
{
	bCheck[y][x] = true;

	queue<pair<int, int>> que;
	que.push(make_pair(x, y));

	while (!que.empty())
	{
		int _x = que.front().first;
		int _y = que.front().second;

		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int _dx = _x + dx[i];
			int _dy = _y + dy[i];

			if (-1 < _dx && _dx < n && -1 < _dy && _dy < n)
			{
				if (value == vec[_dy][_dx])
				{
					if (!bCheck[_dy][_dx])
					{
						bCheck[_dy][_dx] = true;
						que.push(make_pair(_dx, _dy));
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n;

	int result1 = 0;
	int result2 = 0;

	for (int i = 0; i < n; ++i)
		vec[i].resize(n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> vec[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!bCheck[i][j])
			{
				bfs(j, i, vec[i][j]);
				++result1;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			bCheck[i][j] = false;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (R == vec[i][j])
				vec[i][j] = G;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!bCheck[i][j])
			{
				bfs(j, i, vec[i][j]);
				++result2;
			}
		}
	}

	cout << result1 << " " << result2 << endl;
	return 0;
}