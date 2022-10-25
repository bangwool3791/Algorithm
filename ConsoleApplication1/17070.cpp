#include "pch.h"

#define MAX 16
int number{};
int N[MAX][MAX] = {};

bool bChecked[16][16] = {};

//오른쪽 이동
struct Point
{
	Point()
	{}
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	int x{};
	int y{};
};

Point pointX[2]
{
	{1,0},
	{1,1},
};

Point pointY[2] =
{
	{1,1},
	{0,1},
};

Point pointZ[3]
{
	{1,0},
	{1,1},
	{0,1},
};

int g_count{};

void dfs(int x, int y, int state)
{
	cout << x << " " << y << " ";

	if (N[x][y] == 1)
		return;

	if (x < 0 || y < 0 || x >= number || y >= number) {
		return;
	}

	if ( x == number -1 && y == number-1) 
	{
		++g_count;
		return;
	}

	if (state == 0)
	{
		dfs(x + 1, y, 0);
		dfs(x + 1, y + 1, 2);
	}
	else if (state == 1)
	{
		dfs(x, y + 1, 1);
		dfs(x + 1, y + 1, 2);
	}
	else if (state == 2)
	{
		dfs(x + 1, y, 0);
		dfs(x, y + 1, 1);
		dfs(x + 1, y + 1, 2);
	}
}

int main()
{

	cin >> number;

	for (int i{ 0 }; i < 16; ++i)
	{
		for (int j{ 0 }; j < 16; ++j)
		{
			N[i][j] = -1;
		}
	}


	for (int i{ 0 }; i < number; ++i)
	{
		for (int j{ 0 }; j < number; ++j)
		{
			int k{};
			cin >> k;
			N[i][j] = k;
		}
	}
	cout << endl;
	dfs(1, 0, 0);
	dfs(1, 0, 2);

	cout << g_count;
	return 0;
}
