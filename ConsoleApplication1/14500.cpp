#include "pch.h"

int v[500][501];

bool visited[500][501];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int dx1[4] = { 0, 1, 1, 2 };
int dy1[4] = { 0, 0, 1, 0 };

int dx2[4] = { 0, 0, -1, 0 };
int dy2[4] = { 0, 1, 1, 2 };

int dx3[4] = { 0, 0, 1, 0 };
int dy3[4] = { 0, 1, 1, 2 };

//shape1
int dx4[4] = { 0, 1, 1, 2 };
int dy4[4] = { 0, 0, -1, 0 };

int n, m;
int answer;

bool valid(int x, int y, int* arrx, int* arry)
{
	for (int i = 0; i < 4; ++i)
	{
		int dx = x + arrx[i];
		int dy = y + arry[i];
		
		if (0 > dx || dx >= m || 0 > dy || dy >= n)
			return false;
	}

	return true;
}

int shape(int x, int y, int* arrx, int* arry)
{
	int sum = 0;
	if (valid(x, y, arrx, arry))
	{
		for (int i = 0; i < 4; ++i)
		{
			int dx = x + arrx[i];
			int dy = y + arry[i];

			sum += v[dy][dx];
		}
	}
	return sum;
}

void dfs(int x, int y, int depth, int sum)
{
	if (3 == depth)
	{
		answer = max(answer, sum);
		return;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			int _x = x + dx[i];
			int _y = y + dy[i];

			if (0 > _x || _x >= m || 0 > _y || _y >= n)
				continue;

			if (visited[_y][_x])
				continue;

			visited[_y][_x] = true;
			dfs(_x, _y, depth + 1, sum + v[_y][_x]);
			visited[_y][_x] = false;
		}
	}
}

void FuckShape(int x, int y)
{
	int result = 0;
	result = shape(x, y, dx1, dy1);
	if (answer < result)
		answer = result;
	result = shape(x, y, dx2, dy2);
	if (answer < result)
		answer = result;
	result = shape(x, y, dx3, dy3);
	if (answer < result)
		answer = result;
	result = shape(x, y, dx4, dy4);
	if (answer < result)
		answer = result;
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			visited[i][j] = true;
			dfs(j, i, 0, v[i][j]);
			visited[i][j] = false;
			FuckShape(j, i);
		}
	}
	cout << answer << endl;
	return 0;
}