#include "pch.h"
#include <iostream>

using namespace std;

int DP[51][51][51];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		if (DP[0][0][0] == 0)
		{
			DP[0][0][0] = 1;
			return DP[0][0][0];
		}
		else
		{
			return DP[0][0][0];
		}
	}

	 if (a > 20 || b > 20 || c > 20)
	{
		if (DP[20][20][20] == 0)
		{
			DP[20][20][20] = w(20, 20, 20);
			return DP[20][20][20];
		}
		else
		{
			return DP[20][20][20];
		}
	}
	
	 if (a < b && b < c)
	{
		if (DP[a][b][c] == 0)
		{
			DP[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
			return DP[a][b][c];
		}
		else
		{
			return DP[a][b][c];
		}
	}
	else
	{
		if (DP[a][b][c] == 0)
		{
			DP[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c- 1) - w(a - 1, b - 1, c - 1);
			return DP[a][b][c];
		}
		else
		{
			return DP[a][b][c];
		}
	}
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	cout << w(a, b, c) << endl;
	return 0;
}