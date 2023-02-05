#include "pch.h"

bool bCheck[10001];
int w[10001];

int check[101][101]; // 시작점으로부터의 거리 표시
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main()
{
	int N = 0, M = 0;
	cin >> N;
	cin >> M;

	vector<int> V(N * M + 1, 0);

	for (int i{}; i < N; ++i)
	{
		for (int j{}; j < M; ++j)
		{
			int index = i * M + j;
			char ch{};
			cin >> ch;
			V[index] = atoi(&ch);
		}
	}

	queue<pair<int, int>> s;
	s.push(make_pair(0, 0));
	bCheck[0] = true;
	int d{};

	while (!s.empty())
	{
		pair<int, int> p = s.front();
		s.pop();

		int idx = p.second * M +  p.first;

		for (int i{};i < 4; ++i)
		{
			int y = p.second + dx[i];
			int x = p.first + dy[i];

			if (0 <= x && x < M && 0 <= y && y < N)
			{
				int index = y * M + x;
				if (!bCheck[index] && 1 == V[index])
				{
					bCheck[index] = true;
					check[y][x] = check[p.second][p.first] + 1;
					s.push(make_pair(x, y));
					break;
				}
			}
		}
	}
	cout << check[N - 1][M - 1] + 1 << endl;
	return 0;
}