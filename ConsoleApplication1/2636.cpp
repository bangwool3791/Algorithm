#include "pch.h"

int room[100][100];
bool check[100][100];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<pair<int, int>> ice;

int r, c;

int answer = 0;
int t = 0;

void print()
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << room[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bfs()
{
	++t;
	queue<pair<int, int>> que;
	que.push({ 0, 0 });
	check[0][0] = true;

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int _y = y + dy[i];
			int _x = x + dx[i];

			if (0 > _x || _x >= c || 0 > _y || _y >= r)
				continue;

			if (check[_y][_x])
				continue;

			check[_y][_x] = true;

			if (1 == room[_y][_x])
				ice.push_back({ _y,_x });

			if (0 == room[_y][_x])
				que.push({ _y, _x });
		}
	}

	for (int i = 0; i < ice.size(); ++i)
	{
		int y = ice[i].first;
		int x = ice[i].second;

		room[y][x] = 0;
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			check[i][j] = false;
		}
	}

	if (ice.size())
		answer = ice.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> room[i][j];
		}
	}

	bfs();
	print();
	while (ice.size())
	{
		ice.clear();
		bfs();
		print();
	}

	cout << t - 1 << endl;
	cout << answer << endl;
	return 0;
}