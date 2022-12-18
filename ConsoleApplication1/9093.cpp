
#include "pch.h"

int main()
{
	int n;

	cin >> n;

	for (size_t k = 0; k < n + 1; ++k)
	{
		string str;
		getline(cin, str);
		string reverse;
		string result;

		for (size_t i = 0; i < str.size(); ++i)
		{
			if (str[i] != ' ')
			{
				reverse += str[i];
			}
			else
			{
				result.resize(reverse.size());
				for (size_t j = 0; j < reverse.size(); ++j)
				{
					result[reverse.size() - j - 1] = reverse[j];
				}
				if (i != str.size() - 1)
				{
					cout << result << " ";
				}
				else {
					cout << result;
				}
				result.clear();
				reverse.clear();
			}
		}
		cout << '\n';
	}

	return 0;
}