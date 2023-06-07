#include "pch.h"

long long answer;

bool Contain666(long long n)
{
	int cnt = 0;
	
	string str = std::to_string(n);

	for (int i = 0; i < str.size(); ++i)
	{
		if (i + 2 == str.size())
			return false;

		if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6')
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long MovieName = 666;

	int cnt = 0, N = 0;

	cin >> N;

	for (; cnt < N; ++MovieName)
	{
		if (Contain666(MovieName))
		{
			++cnt;
		}

		if (cnt == N)
			break;

	}

	cout << MovieName;

	return 0;
}