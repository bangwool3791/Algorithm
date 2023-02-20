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
	//����� ���� �� 0-2, 1-2
	dp[2] = max(stair[1] + stair[2], stair[0] + stair[2]);
	/*
	* ����� �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�. ��, �� ����� �����鼭 �̾ ���� ����̳�, ���� ���� ������� ���� �� �ִ�.
	* dp[i] = stair[i] + stair[i - 1]
	* dp[i] = stair[i] 
	���ӵ� �� ���� ����� ��� ��Ƽ��� �� �ȴ�. ��, �������� ��ܿ� ���Ե��� �ʴ´�.

	������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.
	i�� ������ ����̶� ����

	* dp[i] = stair[i] + stair[i - 1] + dp[i - 3] (�׵��� ���� ���)
	* dp[i] = stair[i] + dp[i - 1](�׵��� ���� ���)
	* 
	* dp[i] = max(stair[i] + stair[i - 1] + dp[i - 3], stair[i] + dp[i - 1]);
	* �� �������� �� ���, stair[i] + dp[i - 1] ���� �� ��� ��ĭ�� �� �� �ִ�.
	*/
	for (int i = 3; i < n; ++i)
	{
		dp[i] = max(stair[i - 1] + stair[i] + dp[i - 3], stair[i] + dp[i - 2]);
	}
	
	cout << dp[n - 1] << endl;
	return 0;
}