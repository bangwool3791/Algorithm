#include <iostream>
#include <vector>
#include <String>

using namespace std;

void cantor(string& str, int start, int end, int size)
{

	if (size == 1)
	{
		return;
	}
	else
	{
		int len = size / 3;
		
		for (int i = start + len; i < start + len * 2; ++i)
			str[i] = ' ';

		cantor(str, start, len, size / 3);
		cantor(str, start + len * 2, end, size / 3);
	}
}
int main()
{
	int N = 0;

	while (cin >> N)
	{
		string str;

		if (N == 0)
		{
			str += '-';
		}
		else
		{
			for (int i = 0; i < pow(3, N); ++i)
				str += '-';
		}

		cantor(str, 0, str.length(), str.length());
		cout << str << endl;
	}
	return 0;
}
