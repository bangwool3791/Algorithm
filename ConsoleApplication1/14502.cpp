#include "pch.h"

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool bCheck[8 * 8 + 1];
int v[8][8];
int v2[8][8];
int n = 0, m = 0;

int answer = 0;

void swap(int(*a)[8], int(*b)[8])
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
	int map[8][8];
	int cnt = 0;

	swap(map, v2);

	queue<pair<int, int>> que;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (2 == map[i][j])
			{
				que.push({ j,i });
			}
		}
	}


	while (!que.empty())
	{
		int _x = que.front().first;
		int _y = que.front().second;

		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int __x = _x + dx[i];
			int __y = _y + dy[i];

			if (-1 < __x && __x < m && -1 < __y && __y < n)
			{
				if (0 == map[__y][__x])
				{
					map[__y][__x] = 2;
					que.push({ __x, __y });
				}
			}
		}
	}

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < m; ++j)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//cout << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (0 == map[i][j])
			{
				++cnt;
			}

		}
	}
	answer = max(cnt, answer);
}

void routue(int idx)
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
				if (v2[i][j] == 0)
				{
					v2[i][j] = 1;
					routue(idx + 1);
					v2[i][j] = 0;
				}
			}
		}
	}
}

void Input()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}
}
int main()
{
	cin >> n >> m;

	Input();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 0)
			{
				v[i][j] = 1;
				swap(v2, v);
				routue(1);
				v[i][j] = 0;
			}
		}
	}

	cout << answer;
	return 0;
}