#include "pch.h"

unsigned long A[300][300];
unsigned long B[300][300];

enum class DIR
{
	DOWN,
	RIGHT,
	UP,
	LEFT,
};

int main()
{
	int N{}, M{}, R{};

	cin >> N >> M >> R;

	int left{ 1 };
	int right{ M };
	int top{ N };
	int bottom{ 1 };
	int cnt{ 1 };

	for (int i{ 1 }; i <= N; ++i)
	{
		for (int j{ 1 }; j <= M; ++j)
		{
			unsigned long a;
			cin >> a;
			A[i][j] = a;
			B[i][j] = a;
		}
	}
	DIR eDir = DIR::DOWN;

	while (R > 0)
	{
		while ((left < right) && (bottom < top))
		{
			switch (eDir)
			{
			case DIR::DOWN:

				A[cnt + 1][left] = B[cnt][left];

				if (cnt + 1 == top)
				{
					eDir = DIR::RIGHT;
					cnt = left;
				}
				else
				{
					++cnt;
				}

				break;
			case DIR::RIGHT:

				A[top][cnt + 1] = B[top][cnt];

				if (cnt + 1 == right)
				{
					eDir = DIR::UP;
					cnt = top;
				}
				else
				{
					++cnt;
				}
				break;
			case DIR::UP:

				A[cnt - 1][right] = B[cnt][right];

				if (cnt - 1 == bottom)
				{
					eDir = DIR::LEFT;
					cnt = right;
				}
				else
				{
					--cnt;
				}
				break;
			case DIR::LEFT:

				A[bottom][cnt - 1] = B[bottom][cnt];

				if (cnt - 1 == left)
				{
					eDir = DIR::DOWN;

					left++;
					right--;
					top--;
					bottom++;

					cnt = bottom;
				}
				else
				{
					--cnt;
				}
				break;
			}
		}
		for (int i{ 1 }; i <= N; ++i)
		{
			for (int j{ 1 }; j <= M; ++j)
			{
				B[i][j] = A[i][j];
			}
		}
		left = 1;
		right =M;
		top = N;
		bottom = 1;
		cnt = 1;
		--R;
	}

	for (int i{ 1 }; i <= N; ++i)
	{
		for (int j{ 1 }; j <= M; ++j)
		{
			cout << B[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}