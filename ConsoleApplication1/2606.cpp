#include "pch.h"

bool bCheck[101];
int result{};

void dfs(int i, vector<vector<int>>vec)
{
	if (!bCheck[i])
	{
		++result;
		bCheck[i] = true;

		for (int j = 0; j < vec[i].size(); ++j)
		{
			dfs(vec[i][j], vec);
		}
	}
}
int main()
{
	int N = 0, M = 0;
	cin >> N;
	cin >> M;
	vector<vector<int>> vec(N + 1 , vector<int>());
	
	for (int i{}; i < M; ++i)
	{
		int u{}, v{};
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	dfs(1, vec);

	cout << result-1 << endl;
}