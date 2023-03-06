#include "pch.h"

char arr[500];
int decimal[500];

int main()
{
	int idx = 0;
	bool bCheck = false;

	while (true)
	{
		cin >> arr[idx];

		if ('-' == arr[idx])
		{
			bCheck = true;
		}
		else
		{
			decimal[idx] = atoi(&arr[idx]);
		}

		if (bCheck)
		{
			if (0 < decimal[idx])
				decimal[idx] *= -1;
		}
		++idx;
	}

	long long sum = 0;

	for (int i = 0; i < idx; ++i)
	{
		sum += decimal[i];
	}

	cout << sum;
	return 0;
}