#include "pch.h"

vector<pair<int, char>> vec;
deque<pair<int, int>> deq;
int v[101][101];

int dx[4] = { 1, 0, -1 , 0 };
int dy[4] = { 0, -1, 0 , 1 };

int n = 0;

void Input()
{
	cin >> n;

	int m = 0;

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			int a = 0;
			v[i][j] = a;
		}
	}

	cin >> m;

	while (0 < m)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		v[a - 1][b - 1] = 1;
		--m;
	}

	cin >> m;

	while (0 < m)
	{
		int a = 0;
		char b = 0;
		cin >> a >> b;
		vec.push_back({ a, b });
		--m;
	}
}

int Rotation(char c, int a)
{
	if ('D' == c)
	{
		if (0 == a)return 3;
		else if (1 == a)return 0;
		else if (2 == a)return 1;
		else if (3 == a)return 2;
	}
	else if ('L' == c)
	{
		if (0 == a)return 1;
		else if (1 == a)return 2;
		else if (2 == a)return 3;
		else if (3 == a)return 0;
	}
}


void Print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

void Progress()
{
	int t = 0;
	int x = 0;
	int y = 0;
	int d = 0;
	int idx = 0;

	deq.push_back({ x,y });
	v[x][y] = 2;
	while (!deq.empty())
	{
		++t;

		//x = deq.front().first;
		//y = deq.front().second;

		int _x = x + dx[d];
		int _y = y + dy[d];

		int target = v[_x][_y];

		if (0 > _x || 0 > _y || n <= _x || n <= _y || target == 2)
		{
			break;
		}
		else if (0 == target)
		{
			v[_x][_y] = 2;
			deq.push_front({ _x, _y });
			v[deq.back().first][deq.back().second] = 0;
			deq.pop_back();
		}
		else if (1 == target)
		{
			v[_x][_y] = 2;
			deq.push_front({ _x, _y });
		}

		if (idx < vec.size())
		{
			if (t >= vec[idx].first)
			{
				d = Rotation(vec[idx].second, d);
				++idx;
			}
		}
		x = _x;
		y = _y;

	}

	cout << t << endl;
}

int main()
{
	Input();
	Progress();
	return 0;
}