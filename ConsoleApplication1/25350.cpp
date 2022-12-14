#include "pch.h"

int main()
{
	int N, K;
	
	cin >> N >> K;

	vector<int> vec{};

	while (true)
	{
		if (N <= 0)
		{
			break;
		}

		int X;
		cin >> X;
		vec.push_back(X);
		--N;
	}

	sort(vec.begin(), vec.end(), greater<>());

	cout << vec[K - 1];
	return 0;
}