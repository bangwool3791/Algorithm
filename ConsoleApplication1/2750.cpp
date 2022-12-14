
#include "pch.h"

int main()
{
	int N{};

	cin >> N;

	vector<int> vec{};

	while (true)
	{
		if (N <= 0)
		{
			break;
		}
		int M{};

		cin >> M;
		vec.push_back(M);
		--N;
	}

	sort(vec.begin(), vec.end());

	for (auto i{ vec.begin() }; i < vec.end(); ++i)
	{
		cout << *i << endl;
	}
	return 0;
}