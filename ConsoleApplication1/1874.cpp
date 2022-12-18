#include "pch.h"

int main()
{
	long long rescursive;
	cin >> rescursive;
	
	long long m  = 0, n = 1;
	stack<long long> m_stack;
	string result;
	for (long long i = 0; i < rescursive; ++i)
	{
		cin >> m;
		while (n <= m)
		{
			m_stack.push(n);
			result.push_back('+');
			++n;
		}

		if (m_stack.top() == m)
		{
			m_stack.pop();
			result.push_back('-');
		}
	}

	if (!m_stack.empty())
	{
		cout << "NO";
	}
	else
	{
		for (long long i = 0; i < result.size(); ++i)
		{
			cout << result[i] << '\n';
		}
	}
	return 0;
}