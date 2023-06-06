#include "pch.h"

int l, c;

vector<char> answer;

vector<char> A;

bool Check()
{
	int mouem = 0;

	for (int i = 0; i < l; ++i)
	{
		if (answer[i] == 'a' ||
			answer[i] == 'e' ||
			answer[i] == 'i' ||
			answer[i] == 'o' ||
			answer[i] == 'u')
			++mouem;
	}

	if (mouem >= 1 && l - mouem >= 2)
		return true;

	return false;
}

void encode(int depth)
{
	if (answer.size() == l)
	{
		if (Check())
		{
			for (int i = 0; i < l; ++i)
				cout << answer[i];

			cout << endl;
		}
		return;
	}
	else
	{
		for (int i = depth; i < c; ++i)
		{
			answer.push_back(A[i]);
			encode(i + 1);
			answer.pop_back();
		}
	}
}

int main()
{
	cin >> l >> c;
	A.resize(c);

	for (int i = 0; i < c; ++i)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	encode(0);

	return 0;
}