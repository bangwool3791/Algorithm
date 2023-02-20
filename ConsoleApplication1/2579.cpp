#include "pch.h"

int dp[301];
int stair[301];

int main()
{
	int n = 0;
	cin >> n;

	int a = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		stair[i] = a;
	}

	dp[0] = stair[0];
	dp[1] = max(stair[0], stair[0] + stair[1]);
	//계단을 밟은 땐 0-2, 1-2
	dp[2] = max(stair[1] + stair[2], stair[0] + stair[2]);
	/*
	* 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
	* dp[i] = stair[i] + stair[i - 1]
	* dp[i] = stair[i] 
	연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.

	마지막 도착 계단은 반드시 밟아야 한다.
	i를 마지막 계단이라 가정

	* dp[i] = stair[i] + stair[i - 1] + dp[i - 3] (그동안 누적 계단)
	* dp[i] = stair[i] + dp[i - 1](그동안 누적 계단)
	* 
	* dp[i] = max(stair[i] + stair[i - 1] + dp[i - 3], stair[i] + dp[i - 1]);
	* 를 정답으로 한 경우, stair[i] + dp[i - 1] 연속 된 계단 세칸이 될 수 있다.
	*/
	for (int i = 3; i < n; ++i)
	{
		dp[i] = max(stair[i - 1] + stair[i] + dp[i - 3], stair[i] + dp[i - 2]);
	}
	
	cout << dp[n - 1] << endl;
	return 0;
}