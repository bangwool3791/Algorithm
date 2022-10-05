#include "pch.h"

int main()
{
	int N{ 0 }, MAX_VALUE{ 0 }, PROFIT_SUM{ 0 }, TEST_CASE{ 0 };
	
	vector<int> v{}, answer{};
	cin >> TEST_CASE;
	for (size_t j{ 0 }; j < TEST_CASE; ++j)
	{
		cin >> N;
		for (size_t i{ 0 }; i < N; ++i)
		{
			int value{ 0 };
			cin >> value;
			v.push_back(value);
		}
		PROFIT_SUM = 0;
		MAX_VALUE = 0;
		for (int i{ (int)N - 1 }; i >= 0; --i)
		{
			if (MAX_VALUE < v[i])
			{
				MAX_VALUE = v[i];
			}
			else
			{
				PROFIT_SUM += (MAX_VALUE - v[i]);
			}
		}
		answer.push_back(PROFIT_SUM);
		v.clear();
	}

	for (auto elem : answer)
	{
		cout << elem << endl;
	}
	return 0;
}