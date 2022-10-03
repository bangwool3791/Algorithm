#include "pch.h"

char arr[29] = {
	'A','B','C','D','E',
	'F','G' ,'H','I','J'
	,'K','M','N','L','O'
	,'P','Q','R','S','T'
	,'U','V','W','X','Y'
	,'Z','+','-','*' };

int main()
{
	//1. char 버퍼를 준비
	//2. 기호, 스트링 2이면 버퍼에 담는다. 
	size_t cnt{ 0 };
	stack<char> queue{};
	map<char, int> map{};

	cin >> cnt;

	size_t cnt2{ cnt };

	string TempString;
	cin >> TempString;
	size_t TempStringSize{ TempString.size() };

	for (size_t i{ 0 }; i < TempStringSize; ++i)
	{
		queue.push(TempString[i]);
	}

	int value{ 0 };

	for (size_t i{ 0 }; i < cnt2; ++i)
	{
		cin >> value;
		map.emplace(std::make_pair(arr[i], value));
	}
	map.emplace(std::make_pair('+', -1));
	map.emplace(std::make_pair('-', -1));
	map.emplace(std::make_pair('*', -1));
	map.emplace(std::make_pair('/', -1));

	int result{ 0 };

	vector<double> buffer{};

	//스택으로 다시 풀 것.

	size_t _size = queue.size();

	for (size_t i{ 0 }; i < _size; ++i)
{
		char key = queue.top();
		queue.pop();
		int value = map[key];

		if (0 < value)
		{
			buffer.push_back(value);
		}
		else
		{
			if (buffer.size() < 2)
				continue;

			double b = buffer.back();
			buffer.pop_back();
			double a = buffer.back();
			buffer.pop_back();
			switch (key)
			{
			case '+':
				buffer.push_back(a + b);
				break;
			case '-':
				buffer.push_back(a - b);
				break;
			case '*':
				buffer.push_back(a * b);
				break;
			case '/':
				buffer.push_back((double)a / b);
				break;
			}
		}
	}

	cout << std::fixed;
	cout.precision(2);

	for (auto elem : buffer)
	{
		cout << elem;
	}

	return 0;
}