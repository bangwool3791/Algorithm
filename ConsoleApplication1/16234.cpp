#include "pch.h"
/*
* BFS -> 국경이 열리는 나라 조사
* 국경이 열린 나라 중 연합 인구수로 조정
* 반복문 중 한번도 국경이 열리지 않는다면 날짜 출력 후 종료
*/

int v[50][51];
bool bCheck[50][51];
int N, L, R;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1};
int bResult = false;

void clear()
{
	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			bCheck[i][j] = false;
		}
	}
}

void bfs(int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x,y });
	vector<pair<int, int>> vec{};

	vec.push_back({ x, y});

	while (!que.empty())
	{
		int _x = que.front().first;
		int _y = que.front().second;

		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int __x = _x + dx[i];
			int __y = _y + dy[i];

			if (bCheck[__y][__x])
				continue;
			int diff = abs(v[_y][_x] - v[__y][__x]);

			if (L > diff || R < diff)
				continue;

			if(0 > __x || N <= __x || 0 > __y || N <= __y)
				continue;

			bCheck[__y][__x] = true;
			bResult = true;
			que.push({ __x,__y });
			vec.push_back({ __x,__y });
		}
	}

	int size = vec.size();
	long long sum = 0;
	
	for (int i = 0; i < size; ++i)
	{
		int x = vec[i].first;
		int y = vec[i].second;

		sum += v[y][x];
	}

	int avr = sum / size;

	for (int i = 0; i < size; ++i)
	{
		int x = vec[i].first;
		int y = vec[i].second;
		
		v[y][x] = avr;
	}
}

int main()
{
	cin >> N >> L >> R;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> v[i][j];
		}
	}

	int iDay = 0;

	while (true)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (!bCheck[i][j])
				{
					bfs(j, i);
				}
			}
		}

		if (bResult)
		{
			++iDay;
			bResult = false;
		}
		else
		{
			cout << iDay << endl;
			exit(0);
		}

		clear();
	}

	return 0;
}