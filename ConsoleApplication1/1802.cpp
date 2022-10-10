#include "pch.h"

bool verify(char arr[], int start, int last)
{
	if (start >= last)
		return true;

	int begin = start;
	int end = last;

	while (begin < end)
	{
		if (arr[begin] == arr[end])
		{
			return false;
		}
		++begin;
		--end;
	}

	return verify(arr, start, end-1);
}

int main()
{
	int T{ 0 };

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		char str[3010] = {};
		cin >> str;
		if (strlen(str) % 2 == 0)
		{
			cout << "NO";
		}
		else if (verify(str, 0, strlen(str) - 1))
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << endl;
	}
	return 0;
}