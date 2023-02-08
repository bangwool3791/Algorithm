#include "pch.h"

vector<int> vec[1001];
bool bCheck[1001];
int u = 0, v = 0;
int result = 0;

void dfs(int i)
{
	bCheck[i] = true;
	
	for (int j = 0; j < vec[i].size(); ++j)
	{
		int idx = vec[i][j];
		if (!bCheck[idx])
		{
			dfs(idx);
		}
	}
}
int main()
{
	int N = 0;
	int M = 0;

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!bCheck[i])
		{
			++result;
			dfs(i);
		}
	}

	cout << result << endl;
	return 0;
}