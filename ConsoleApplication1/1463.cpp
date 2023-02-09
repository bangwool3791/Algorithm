#include "pch.h"

#define INF 1000001

int dp[1000001];

int main()
{
	memset(dp, INF, sizeof(int) * 1000001);
	int n = 0;
	
	dp[0] = 0;
	dp[1] = 0;

	cin >> n;

	for (int i = 2; i <= n; ++i)
	{
		if (dp[i] > dp[i-1] + 1)
			dp[i] = dp[i - 1] + 1;

		if (0 == (i % 2) && dp[i] > dp[i/2] + 1)
			dp[i] = dp[i/2] + 1;

		if (0 == (i % 3) && dp[i] > dp[i / 3] + 1)
			dp[i] = dp[i / 3] + 1;
	}

	cout << dp[n] << endl;

	return 0;

}