#include "pch.h"

char A[50][50];
int N, M;

int paint_cnt = 0;

char WB[8][8] =
{
 'W','B','W','B','W','B','W','B',
 'B','W','B','W','B','W','B','W',
 'W','B','W','B','W','B','W','B',
 'B','W','B','W','B','W','B','W',
 'W','B','W','B','W','B','W','B',
 'B','W','B','W','B','W','B','W',
 'W','B','W','B','W','B','W','B',
 'B','W','B','W','B','W','B','W'
};

char BW[8][8] =
{
 'B','W','B','W','B','W','B','W',
 'W','B','W','B','W','B','W','B',
 'B','W','B','W','B','W','B','W',
 'W','B','W','B','W','B','W','B',
 'B','W','B','W','B','W','B','W',
 'W','B','W','B','W','B','W','B',
 'B','W','B','W','B','W','B','W',
 'W','B','W','B','W','B','W','B'
};

int IsWB(int x, int y)
{
	int result = 0;

	for (int i = y; i < y + 8; ++i)
	{
		for (int j = x; j < x + 8; ++j)
		{
			if (A[i][j] != WB[i - y][j - x])
				++result;
		}
	}
	return result;
}

int IsBW(int x, int y)
{
	int result = 0;

	for (int i = y; i < y + 8; ++i)
	{
		for (int j = x; j < x + 8; ++j)
		{
			if (A[i][j] != BW[i - y][j - x])
				++result;
		}
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> A[i][j];
		}
	}

	int answer = 50 * 50;

	for (int i = 0; i < N ; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int WBCnt = IsWB(j, i);
			int BWCnt = IsBW(j, i);

			int cnt = min(WBCnt, BWCnt);

			answer = min(cnt, answer);
		}
	}

	cout << answer;
	return 0;
}