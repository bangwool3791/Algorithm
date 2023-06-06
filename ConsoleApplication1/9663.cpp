#include "pch.h"

int col[16];
int n;
int ans = 0;

void queen(int x)
{
	if (x == n)
	{
		ans++;
	}
	else
	{
		//행
		for (int i = 0; i < n; ++i)
		{
			col[x] = i;

			bool bCan = true;
			//열
			for (int j = 0; j < x; ++j)
			{
				//이미 말이 놓여져 있는지 확인한다.
				if (col[x] == col[j] &&
					//대각선 인지 확인한다.
					abs(col[x] - col[j]) == abs(x - j))
				{
					//같은 행에 말이 있으면 break
					bCan = false;
					break;
				}
			}
			if (bCan)
			{
				queen(x + 1);
			}
		}
	}
}

int main()
{
	cin >> n;

	queen(0);

	cout << n << endl;
}