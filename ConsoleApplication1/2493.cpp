#include "pch.h"

stack<pair<int, int>> st;
int n = 0;

int main()
{
	cin >> n;
	int value = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> value;

		//1 연속 3개 들어오면, 3개다 0으로 출력한다.
		while (!st.empty())
		{
			if (value < st.top().second)
			{
				cout << st.top().first << " ";
				break;
			}

			st.pop();
		}

		if (st.empty())
			cout << "0" << " ";

		st.push({ i + 1, value });
	}

	return 0;
}