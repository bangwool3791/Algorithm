#include "pch.h"

int main()
{
	queue<int> queue;

	int n = 0, k = 0;

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		queue.push(i + 1);
	}
	int value = 0;
	cout << "<";
	while (queue.size() > 1)
	{
		for (int i = 1; i < k; ++i)
		{
			value = queue.front();
			queue.pop();
			queue.push(value);
		}
		value = queue.front();
		queue.pop();
		cout << value;
		cout << ", ";
	}
	value = queue.front();
	cout << value;
	cout << ">";
	cout << '\n';
	queue.pop();
	return 0;
}