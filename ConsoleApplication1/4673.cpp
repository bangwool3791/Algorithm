#include "pch.h"

int d(int n)
{
	int sum = n;

	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	bool bCheck[10001]{ false };

	for (int i = 1; i <= 10000; ++i)
	{
		int n = d(i);

		if (n < 10001)
			bCheck[n] = true;
	}

	for (int i = 1; i <= 10000; ++i)
	{
		if (!bCheck[i])
			cout << i << endl;
			
	}
	return 0;
}