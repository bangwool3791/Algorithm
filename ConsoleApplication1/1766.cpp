#include "pch.h"

vector<int> vec[32001];

int best[32001];

int N, M;

int main()
{
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;

		best[b]++;
		vec[a].push_back(b);
	}

	priority_queue<int,vector<int>, greater<int>> que;

	for (int i = 1; i <= N; ++i)
	{
		if (0 == best[i])
			que.push({ i });
	}

	while (!que.empty())
	{
		int idx = que.top();
		que.pop();

		cout << idx << " ";

		for (int i = 0; i < vec[idx].size(); ++i)
		{
			int j = vec[idx][i];
			
			--best[j];

			if (0 == best[j])
				que.push(j);
		}
	}
	return 0;
}