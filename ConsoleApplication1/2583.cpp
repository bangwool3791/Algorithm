#include "pch.h"

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int v[100][101];
bool bCheck[100][101];

int cnt;
int area;

vector<int> answer;

int m = 0, n = 0, k = 0;

void pirint()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

void marking(int x1, int y1, int x2, int y2)
{
	for (int i = y1; i < y2; ++i)
	{
		for (int j = x1; j < x2; ++j)
		{
			v[i][j] = -1;
		}
	}
}

void bfs(int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x,y });
	bCheck[y][x] = true;
	area = 1;

	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int _x = x + dx[i];
			int _y = y + dy[i];

			if (-1 < _x && _x < m && -1 < _y && _y < n)
			{
				if (!bCheck[_y][_x] && -1 != v[_y][_x])
				{
					++area;
					bCheck[_y][_x] = true;
					que.push({ _x, _y });
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;

	int x1, x2, y1, y2;

	for (int i = 0; i < k; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		marking(x1, y1, x2, y2);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (-1 != v[i][j] && !bCheck[i][j])
			{
				++cnt;
				bfs(j, i);
				answer.push_back(area);
			}
		}
	}

	cout << cnt << endl;
	
	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";

	return 0;
}