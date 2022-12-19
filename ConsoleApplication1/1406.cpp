#include "pch.h"

int main()
{
	list<char> list;
	auto iter = list.end();

	char data[2];
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		list.push_back(str[i]);
	}
	int n = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> data;

		if (!strcmp(data, "P"))
		{
			cin >> data;

			list.insert(iter, data[0]);
		}
		else if (!strcmp(data, "L"))
		{
			if (iter != list.begin())
				--iter;
		}
		else if (!strcmp(data, "D"))
		{
			if (iter != list.end())
				++iter;
		}
		else if (!strcmp(data, "B"))
		{
			if (iter != list.begin())
			{
				--iter;
				iter = list.erase(iter);
			}
		}
	}
	
	for (auto iter{ list.begin() }; iter != list.end(); ++iter)
	{
		cout << *iter;
	}
	return 0;
}