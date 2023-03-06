#include "pch.h"

#define INF 987654321

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int v[101][101];
bool bCheck[101][101];

int n = 0;
int iMax = 0;
long long cnt = 0;
long long answer = 0;
void bfs(int x, int y, int k)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	bCheck[y][x] = true;

	while (!que.empty())
	{
		int _x = que.front().first;
		int _y = que.front().second;

		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int __x = _x + dx[i];
			int __y = _y + dy[i];

			if (-1 < __x && __x < n && -1 < __y && __y < n)
			{
				if (!bCheck[__y][__x] && k < v[__y][__x])
				{
					bCheck[__y][__x] = true;
					que.push({ __x,__y });
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
			bCheck[i][j] = false;
		}
	}
}

void Input()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];

			if (iMax < v[i][j])
				iMax = v[i][j];
		}
	}
}

int main()
{
	cin >> n;

	Input();

	for (int k = 0; k <= iMax; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!bCheck[i][j] && k < v[i][j])
				{
					++cnt;
					bfs(j, i, k);
				}
			}
		}
		if (answer < cnt)
			answer = cnt;
		cnt = 0;
		clear();
	}

	cout << answer << endl;
	return 0;
}