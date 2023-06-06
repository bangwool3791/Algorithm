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
		//��
		for (int i = 0; i < n; ++i)
		{
			col[x] = i;

			bool bCan = true;
			//��
			for (int j = 0; j < x; ++j)
			{
				//�̹� ���� ������ �ִ��� Ȯ���Ѵ�.
				if (col[x] == col[j] &&
					//�밢�� ���� Ȯ���Ѵ�.
					abs(col[x] - col[j]) == abs(x - j))
				{
					//���� �࿡ ���� ������ break
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