#include "pch.h"

bool dp[2'000'003];
int answer[2'000'003];

int main()
{
	int n = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int number = 0;
		int index = 0;
		cin >> number;

		if (number > 0)
		{
			index = number + 1'000'001;
		}
		else
		{
			index = abs(number);
		}

		if (!dp[index])
		{
			dp[index] = true;

			answer[index] = number;
		}
	}

	for (int i = 0; i < 2'000'001; ++i)
	{
		if(dp[i])
			cout << answer[i] << endl;
	}

	return 0;
}