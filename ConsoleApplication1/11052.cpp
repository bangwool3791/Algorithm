#include "pch.h"

int dp[10001];

/*
* DP[1] = DP[1]
* DP[2] = max(DP[1] + DP[1], DP[2]);
* DP[3] = max(DP[1] + DP[2], DP[3]);
* DP[3] = max(DP[2] + DP[2], DP[3]);
* DP[4] = max(DP[1] + DP[3], DP[4]);
* DP[4] = max(DP[2] + DP[2], DP[4]);
* DP[4] = max(DP[3] + DP[1], DP[4]);
* DP[5] = max(DP[1] + DP[4], DP[5]);
* DP[5] = max(DP[2] + DP[3], DP[5]);
* DP[5] = max(DP[3] + DP[2], DP[5]);
* DP[5] = max(DP[4] + DP[1], DP[5]);
* DP[N] = max(DP[i] + DP[N-i], DP[N]);
*/
int main()
{
	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> dp[i];
	}

	int a = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			dp[i] = max(dp[i - j] + dp[j], dp[i]);
		}
	}

	cout << dp[n];
	return 0;
}