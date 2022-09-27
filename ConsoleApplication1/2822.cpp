#pragma once
#include <iostream>
#include <math.h>

#include <vector>
#include <map>

#include <algorithm>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last) {
	if (first == last) return;
	auto pivot = *std::next(first, std::distance(first, last) / 2);
	ForwardIt middle1 =
		std::partition(first, last, [pivot](const auto& em) { return em.Value > pivot.Value; });
	ForwardIt middle2 = std::partition(
		middle1, last, [pivot](const auto& em) { return !(pivot.Value > em.Value); });
	quicksort(first, middle1);
	quicksort(middle2, last);
}

typedef struct Pair
{
	int Value;
	int Id;
};

int main()
{
	vector<Pair> v{}, r{};
	Pair st{};
	int INDEX = 1;
	while (INDEX <= 8)
	{
		cin >> st.Value;
		st.Id = INDEX;
		v.push_back(st);
		++INDEX;
	}

	quicksort(std::begin(v), std::end(v));
	
	int Sum{ 0 };
	for(int i{0}; i < 5; ++i)
	{
		Sum += v[i].Value;
		r.push_back(v[i]);
	}

	cout << Sum << endl;

	std::sort(std::begin(r), std::end(r), [&](const Pair& a, const Pair& b)
	{
			if (a.Id > b.Id)
				return false;
			else return true;
	});
	for (size_t i{ 0 }; i < 5; ++i)
	{
		cout << r[i].Id  << " ";
	}

	return 0;
}