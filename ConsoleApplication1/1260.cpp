#include "pch.h"

void dfs(vector<vector<int>>& vec, vector<bool>& visited, int V)
{

	visited[V] = true;
	cout << V << ' ';

	for (int i{ 0 }; i < vec[V].size(); ++i)
	{
		int y = vec[V][i];
		if(!visited[y])
			dfs(vec, visited, y);
	}
}

void bfs(vector<vector<int>>& vec, vector<bool>& visited, int V)
{
	queue<int> que{};

	int start{ V };
	que.push(start);
	visited[start] = true;
	cout << V << ' ';
	while (!que.empty())
	{
		int a = que.front();
		que.pop();
		
		for (int i{ 0}; i < vec[a].size(); ++i)
		{
			int b = vec[a][i];
			if (!visited[b])
			{
				cout << b << ' ';
				que.push(b);
				visited[b] = true;
			}

		}
	}
}

int main()
{
	int N{}, M{}, V{};

	cin >> N;
	
	vector<vector<int>> vec(N +1);
	vector<bool> visited(N + 1 );
	vector<bool> visited2(N + 1);

	cin >> M;
	cin >> V;

	for (int i{1}; i < M+1; ++i)
	{
		int v{}, t{};
		cin >> v >> t;
		vec[v].push_back(t);
		vec[t].push_back(v);
	}

	for (int i{ 0 }; i < N +1; ++i)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(vec, visited, V);
	cout << endl;
	bfs(vec, visited2, V);
	cout << endl;
	return 0;
}