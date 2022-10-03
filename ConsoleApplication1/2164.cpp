#include "pch.h"

int main()
{
	list<int> v;
	int Value{};

	cin >> Value;

	if (1 > Value || Value > 500000)
	{
		return 0;
	}

	for (int i{ 1 }; i <= Value; ++i)
	{
		v.push_front(i);
	}

	if (v.size() <= 0)
		return 0;

	while (v.size() != 1)
	{
		v.pop_back();
		auto t = v.back();
		v.pop_back();
		v.push_front(t);
	}
	cout << v.front();
	return 0;
}