#include "pch.h"

vector<vector<int>> vec{};
bool bCheck[50][50 + 1];
int cnt[1001];
int M = 0, N = 0;

int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1,  0 ,-1 };

void dfs(int _x, int _y)
{
	if (1 == vec[_x][_y] && !bCheck[_x][_y])
	{
		bCheck[_x][_y] = true;

		for (int i{}; i < 4; ++i)
		{
			int x = _x + dx[i];
			int y = _y + dy[i];

			if(-1 < x && x < M && -1 < y && y < N)
				dfs(x, y);
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> M >> N;
		vec.resize(M);

		for (int j = 0; j < M; ++j)
		{
			vec[j].resize(N);
		}

		int K;
		cin >> K;

		for (int j = 0; j < K; ++j)
		{
			int a, b;
			cin >> a >> b;
			vec[a][b] = 1;
		}

		for (int j = 0; j < M; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				if (1 == vec[j][k])
				{
					if (!bCheck[j][k])
					{
						++cnt[i];
						dfs(j, k);
					}
				}
			}
		}

		for (int j = 0; j < 50; ++j)
		{
			for (int k = 0; k < 50; ++k)
			{
				bCheck[j][k] = false;
			}
		}

		for (int j = 0; j < M; ++j)
		{
			vec[j].clear();
		}

		vec.clear();

	}

	for (int i{}; i < T; ++i)
	{
		cout << cnt[i] << endl;
	}
	return 0;
}