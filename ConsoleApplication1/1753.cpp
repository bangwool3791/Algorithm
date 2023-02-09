#include "pch.h"

//https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-1753%EB%B2%88-%EC%B5%9C%EB%8B%A8%EA%B2%BD%EB%A1%9C-CC

#define INF 987654321

vector<pair<int, int>> node[20002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int value[20002];

int main()
{
	int n = 0, e = 0, k = 0, u = 0, v = 0, w = 0;

	cin >> n >> e;

	cin >> k;

	for (int i = 0; i < e; ++i)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= n; ++i)
	{
		value[i] = INF;
	}

	value[k] = 0;
	pq.push(make_pair(0, k));

	while (!pq.empty())
	{
		int x = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[u].size(); ++i)
		{
			int v = node[u][i].first;
			int w = node[u][i].second;

			if (x + w < value[v])
			{
				value[v] = x + w;
				pq.push(make_pair(x + w, v));
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (value[i] == INF) printf("INF\n");
		else printf("%d\n", value[i]);

	return 0;
}