// Beackjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"

int main()
{
	vector<int> v{};
	int N{ 0 }, K{0};
	int Denom{ 1 }, Numeric{ 1000000000 };
	
	cin >> N;

	while (N < Numeric)
	{
		Numeric /= 10;
	}
	Denom = Numeric;

	while (Denom > 0.1f)
	{
		v.push_back(N / Denom);
		N -= v[K] * Denom;
		++K;
		Denom /= 10;
	}

	auto f1{ [](int a, int b)
	{
		if (a > b)
			return true;
		else
			return false;
	}};

	std::sort(std::begin(v), std::end(v), f1);

	for (auto elem : v)
	{
		cout << elem;
	}
	return 0;
}