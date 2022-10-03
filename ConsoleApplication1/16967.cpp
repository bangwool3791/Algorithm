#include "pch.h"

int main()
{
	int H{ 0 }, W{ 0 }, X{ 0 }, Y{ 0 };
	cin >> H >> W >> X >> Y;

	if (2 > H || H > 300)
		return 0;

	if (2 > W || W > 300)
		return 0;

	if (1 > X || X >= H)
		return 0;

	if (1 > Y || Y >= W)
		return 0;

	vector<vector<int>> v(H + X);
	
	for (int i{ 0 }; i < H + X; ++i)
	{
		v[i].resize(W + Y);
	}

	vector<vector<int>> answer(H);

	for (int i{ 0 }; i < H; ++i)
	{
		answer[i].resize(W);
	}

	for (int i = 0; i < H + X; ++i)
	{
		for (int j = 0; j < W + Y; ++j)
		{
			int k{ 0 };
			cin >> k;
			v[i][j] = k;
		}
	}

	
	for (int i{ 0 }; i < H; ++i)
	{
		for (int j{ 0 }; j < W; ++j)
		{
			if (i < X || j < Y)
			{
				answer[i][j] = v[i][j];
			}
			else 
			{
				answer[i][j] = v[i][j] - answer[i - X][j - Y];
			}
		}
	}

	for (auto elem : answer)
	{
		for (auto elem2 : elem)
		{
			cout << elem2 << ' ';
		}
		cout << endl;
	}
	return 0;
}