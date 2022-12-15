#include "pch.h"

int main()
{
	int n{};
	vector<long long>	 x1{}, x2{};
	cin >> n;

	for (int i{}; i < n; ++i)
	{
		int x{};
		cin >> x;
		x1.push_back(x);
		x2.push_back(x);
	}

	sort(x1.begin(), x1.end());
	x1.erase(unique(x1.begin(), x1.end()), x1.end());

	for (size_t i{}; i < n; ++i)
	{
		cout << lower_bound(x1.begin(), x1.end(), x2[i]) - x1.begin() << " ";
	}
	return 0;
}