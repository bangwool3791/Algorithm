#include "pch.h"

int N;
long long a[10][101];

int main()
{
	cin >> N;

	/*
	* �� -> �� �ڸ� 
	* �� -> �� �ڸ� ��
	*/
	for (int i = 0; i < 10; ++i)
		a[i][0] = 1;

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < 9; ++j)
		{
			/*
			* �� �ڸ� ���� ���� �� ����� ���� ���� ��Ų��.
			*/
			a[j][i] = (a[j - 1][i - 1] + a[j + 1][i - 1]) % 1000000000;
		}

		a[0][i] = a[1][i - 1] % 1000000000;
		a[9][i] = a[8][i - 1] % 1000000000;
	}

	long long result = 0;
	/*
	* ���ڸ� �� ��ŭ ���
	*/
	for (int i = 1; i <= 9; ++i)
	{
		result += a[i][N - 1];
	}

	cout << result % 1000000000 << endl;
	return 0;
}