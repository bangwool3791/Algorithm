#include "pch.h"

int dice[6];
int r = 0, c = 0;
int v[21][21];
int n = 0, m = 0, k = 0;

bool valid(int x, int y)
{
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;

	return false;
}

void East()
{
	int temp[6];

	for (int i = 0; i < 6; ++i)
		temp[i] = dice[i];

	dice[0] = temp[3];
	dice[3] = temp[5];
	dice[5] = temp[2];
	dice[2] = temp[0];
}

void West()
{
	int temp[6];

	for (int i = 0; i < 6; ++i)
		temp[i] = dice[i];

	dice[0] = temp[2];
	dice[3] = temp[0];
	dice[5] = temp[3];
	dice[2] = temp[5];
}

void South()
{
	int temp[6];

	for (int i = 0; i < 6; ++i)
		temp[i] = dice[i];

	dice[0] = temp[4];
	dice[1] = temp[0];
	dice[5] = temp[1];
	dice[4] = temp[5];
}

void North()
{
	int temp[6];

	for (int i = 0; i < 6; ++i)
		temp[i] = dice[i];

	dice[0] = temp[1];
	dice[1] = temp[5];
	dice[5] = temp[4];
	dice[4] = temp[0];
}

int main()
{
	cin >> n >> m >> r >> c >> k;
	int cmd = 0, x = 0, y = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}

	while (k--)
	{
		cin >> cmd;

		if (1 == cmd)
		{	
			x = c + 1;
			y = r;
		}
		else if (2 == cmd)
		{
			x = c - 1;
			y = r;
		}
		else if (3 == cmd)
		{
			x = c;
			y = r - 1;
		}
		else if (4 == cmd)
		{
			x = c;
			y = r + 1;
		}

		if (!valid(x, y))
			continue;

		c = x;
		r = y;

		if (1 == cmd)
			East();
		else if (2 == cmd)
			West();
		else if (3 == cmd)
			North();
		else if (4 == cmd)
			South();

		if (0 == v[r][c])
			v[r][c] = dice[5];
		else
		{
			dice[5] = v[r][c];
			v[r][c] = 0;
		}
		cout << dice[0] << endl;
	}

	return 0;
}