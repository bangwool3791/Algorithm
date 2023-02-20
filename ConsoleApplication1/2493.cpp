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

		//1 ���� 3�� ������, 3���� 0���� ����Ѵ�.
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