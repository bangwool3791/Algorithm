#include "pch.h"

priority_queue<int, vector<int>, greater<int>> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	long long result = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int data = 0;
		cin >> data;
		que.push(data);
	}

	while (1 < que.size())
	{
		int a = que.top();
		que.pop();
		int b = que.top();
		que.pop();

		result += a + b;
		que.push(a + b);
	}
	cout << result << endl;
	return 0;
}