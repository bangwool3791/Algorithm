#include "pch.h"

vector<int> v;
vector<int> answer;

int n = 0;
int k = 0;

void dfs(int start, int depth)
{
	if (6 == depth)
	{
		for (int i = 0; i < 6; ++i)
			cout << answer[i] << " ";

		cout << endl;
		return;
	}

	for (int i = start; i < n; ++i)
	{
		answer[depth] = v[i];

		dfs(i + 1, depth + 1);
	}
	return;
}
int main()
{
	answer.resize(7);

	int a = 0;

	while (true) 
	{
		cin >> n;

		if (!n)
			break;

		v.resize(n + 1);

		for (int i = 0; i < n; ++i)
		{
			cin >> k;
			v[i] = k;
		}

		dfs(0, 0);
	}
	return 0;
}