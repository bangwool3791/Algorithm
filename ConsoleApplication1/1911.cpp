#include "pch.h"

int main()
{
	int N{}, L{};
	cin >> N >> L;
	vector<pair<int, int>> vec(N);
	for (int i{}; i < N; ++i)
	{
		int a{}, b{};
		cin >> a >> b;

		vec[i] = pair{ a,b };
	}

	sort(vec.begin(), vec.end());

	int next = 0;
	int answer = 0;
	for (int i{}; i < N; ++i)
	{
		if (next < vec[i].first)
			next = vec[i].first;

		while (next < vec[i].second)
		{
			next += L;
			++answer;
		}
	}
	cout << answer;
	return 0;
}