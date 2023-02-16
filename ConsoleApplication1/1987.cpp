#include "pch.h"

bool str[28];
int v[21][21];
bool bCheck[21][21];

int r = 0, c = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int answer = 0;

void dfs(int x, int y, int idx)
{
	int __idx = v[y][x];
	str[__idx] = true;

	if (answer < idx)
		answer = idx;

	bCheck[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int _x = x + dx[i];
		int _y = y + dy[i];

		if (-1 < _x && _x < c && -1 < _y && _y < r)
		{
			int _idx = v[_y][_x];

			if (!str[_idx] && !bCheck[_y][_x])
			{
				dfs(_x, _y, idx + 1);
				bCheck[_y][_x] = false;
				str[_idx] = false;
			}
		}
	}

}

void clear()
{
	for (int i = 0; i < 28; ++i)
	{
		str[i] = false;
	}

	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			bCheck[i][j] = false;
		}
	}
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			char ch;
			cin >> ch;
			
			v[i][j] = (int)(ch - 0x40);
		}
	}

	clear();

	dfs(0, 0, 1);

	cout << answer << endl;
	return 0;
}