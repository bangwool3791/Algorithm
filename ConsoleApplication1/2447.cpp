#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_star(vector<vector<char>>& star, int sColumn, int eColumn, int sRow, int eRow)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 1 && j == 1)
			{

			}
			else
				star[sRow + i][sColumn + j] = '*';
		}
	}
}

void func_star(vector<vector<char>>& star, int sColumn, int eColumn, int sRow, int eRow, int N)
{
	if (3 == N)
	{
		print_star(star, sColumn, eColumn, sRow, eRow);
		return;
	}
	else
	{
		int Size = N / 3;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (i == 1 && j == 1)
				{

				}else
					func_star(star, sColumn + j * Size, sColumn + (j + 1) * Size, sRow + i * Size, sRow + (i + 1) * Size, Size);
			}
		}
	}
}

int main()
{
	int N = 0;
	cin >> N;

	vector<vector<char>> star = vector<vector<char>>(N, vector<char>(N, ' '));
	func_star(star, 0, N, 0, N, N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << star[i][j];
		}
		cout << endl;
	}
	return 0;
}