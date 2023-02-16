#include "pch.h"

#define INF 987654321

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int v[101][101];
bool flag[101][101];

int n = 0;
int cnt = 0;

long long answer[101];

void dfs(int x, int y, int k)
{
	flag[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int _x = x + dx[i];
		int _y = y + dy[i];

		if (0 < _x && _x <= n && 0 < _y && _y <= n)
		{
			if (false == flag[_y][_x] && k < v[_y][_x])
			{
				dfs(_x, _y, k);
			}
		}
	}
}

void clear()
{
	for(int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			flag[i][j] = false;
		}
	}
}
int main()
{
	int h = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int a = 0;
			cin >> a;
			v[i][j] = a;

			if (h < v[i][j])
				h = v[i][j];
		}
	}

	for (int k = 1; k <= 100; ++k)
	{
		clear();

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (k < v[i][j] && false == flag[i][j])
				{
					++cnt;
					dfs(j, i, k);
				}
			}
		}
		if (!cnt)
		{
			answer[k] = 1;
		}
		else
		{
			answer[k] = cnt;
		}
		cnt = 0;
	}

	long long output = 1;
	for (int i = 0; i <= h; ++i)
	{
		if (output < answer[i])
		{
			output = answer[i];
		}
	}

	cout << output << endl;
	return 0;
}