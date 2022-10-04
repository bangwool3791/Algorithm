#include "pch.h"

int main()
{
	int n{ 0 };
	cin >> n;
	vector<int> vec;
	
	for(size_t i{0}; i < n; ++i)
	{
		int value;
		cin >> value;
		vec.push_back(value);
	}

	sort(vec.begin(), vec.end());

	int cnt{ 0 };
	while(true)
	{
		if (vec.size() == 1)
			break;

		vec[vec.size() - 2] += vec[vec.size() - 1];
		vec.pop_back();
		++cnt;
		vec[0]--;

		if (vec[0] == 0)
		{
			for (size_t j{ 0 }; j < vec.size() -1; ++j)
			{
				vec[j] = vec[j + 1];
			}
			vec.pop_back();
		}
	}
	return 0;
}