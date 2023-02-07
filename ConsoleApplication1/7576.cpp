#include "pch.h"
//#include <bits/stdc++.h>
//using namespace std;

queue<pair<int, int>> que;
vector<vector<int>> vec{};
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int M = 0, N = 0;

void bfs()
{
	while (!que.empty())
	{
		pair<int, int> p = que.front();
		que.pop();
		
		int _x = p.first;
		int _y = p.second;

		for (int i = 0; i < 4; ++i)
		{
			int _x2 = _x + dx[i];
			int _y2 = _y + dy[i];

			if (-1 < _x2 && _x2 < M && -1 < _y2 && _y2 < N)
			{
				if (0 == vec[_y2][_x2])
				{
					vec[_y2][_x2] = vec[_y][_x] + 1;
					que.push(make_pair(_x2, _y2));
				}
			}
		}
	}
}
int main()
{
	int result{};

	cin >> M >> N;

	vec.resize(N);

	for (int i = 0; i < N; ++i)
	{
		vec[i].resize(M);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int value = 0;
			cin >> value;
			vec[i][j] = value;

			if (1 == value)
				que.push(make_pair(j, i));
		}
	}

	bfs();

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (0 == vec[i][j])
			{
				cout << -1 << endl;
				return 0;
			}
			else
			{
				if (result < vec[i][j])
					result = vec[i][j];
			}
		}
	}

	cout << result - 1<< endl;
	return 0;
}