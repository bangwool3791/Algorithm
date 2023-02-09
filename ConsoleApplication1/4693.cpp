#include "pch.h"

int arr[51][51];

bool bCheck[51][51];

int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int w = 0, h = 0;

void bfs(int x, int y)
{
	queue<pair<int, int>> que;
	que.push(make_pair(x, y));

	bCheck[y][x] = true;

	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 8; ++i)
		{
			int _dx = x + dx[i];
			int _dy = y + dy[i];

			if (-1 < _dx && _dx < w && -1 < _dy && _dy < h)
			{
				if (1 == arr[_dy][_dx] && !bCheck[_dy][_dx])
				{
					bCheck[_dy][_dx] = true;
					que.push(make_pair(_dx, _dy));
				}
			}
		}
	}
}

int main()
{
	vector<int> vec{};

	int result = 0;

	while (true)
	{
		cin >> w >> h;

		if (0 == w && 0 == h)
			break;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				int a = 0;
				cin >> a;
				arr[i][j] = a;
			}
		}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (1 == arr[i][j] && !bCheck[i][j])
				{
					bfs(j, i);
					++result;
				}
			}
		}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				arr[i][j] = 0;
				bCheck[i][j] = false;
			}
		}
		vec.push_back(result);
		result = 0;
	}

	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << endl;
	return 0;
}