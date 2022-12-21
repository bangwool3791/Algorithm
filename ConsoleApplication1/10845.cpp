#include "pch.h"

int main()
{
	queue<int> queue;

	int n;
	char ch[6];
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> ch;

		if (!strcmp(ch, "push"))
		{
			int a = 0;
			cin >> a;
			queue.push(a);
		}
		else if (!strcmp(ch, "pop"))
		{
			if (!queue.empty())
			{
				int a = queue.front();
				queue.pop();
				cout << a << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (!strcmp(ch, "size"))
		{
			cout << queue.size() << '\n';
		}
		else if (!strcmp(ch, "empty"))
		{
			cout << queue.empty() << '\n';
		}
		else if (!strcmp(ch, "front"))
		{
			if (!queue.empty())
			{
				int a = queue.front();
				cout << a << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (!strcmp(ch, "back"))
		{
			if (!queue.empty())
			{
				int a = queue.back();
				cout << a << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}