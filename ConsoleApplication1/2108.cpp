
#include "pch.h"

typedef std::function<bool(std::pair<int, int>, std::pair<int, int>)> Comparator;

int main()
{
	vector<int> vec{};
	map<int, int> map{};

	int N{};
	cin >> N;

	while (true)
	{
		if (N <= 0)
			break;
		
		int a;
		cin >> a;
		vec.push_back(a);
		++map[a];
		--N;
	}

	double sum{};

	for (int i{}; i < vec.size(); ++i)
	{
		sum += vec[i];
	}

	double avr = sum / vec.size();
	double temp = fabs(avr);

	if (temp - (int)temp >= 0.5f)
	{
		temp = ceilf(temp);
	}
	else {
		temp = floorf(temp);
	}

	if (avr < 0 && temp != 0)
	{
		temp *= -1.f;
	}

	sort(vec.begin(), vec.end(), less());
	
	Comparator compFunctor = [](std::pair<int, int> elem1, std::pair<int, int> elem2)
	{
		if (elem1.second > elem2.second)
		{
			return true;
		}
		else if (elem1.second == elem2.second)
		{
			if (elem1.first < elem2.first)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	};

	cout << temp << endl;
	cout << vec[vec.size() / 2] << endl;

	//분기 처리 필요
	std::multiset<std::pair<int, int>, Comparator> set(
		map.begin(), map.end(), compFunctor);
	
	if (1 < set.size())
	{
		int a{}, b{};
		auto iter = set.begin();
		a = iter->second;
		++iter;
		b = iter->second;

		if (a == b)
			cout << iter->first << endl;
		else
			cout << set.begin()->first << endl;
	}
	else 
	{
		auto iter = map.begin();
		cout << iter->first << endl;
	}

	cout << vec[vec.size() -1] - vec[0] << endl;
	return 0;
}