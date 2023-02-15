#include "pch.h"

#define value pair<int, int>
#define INF 987654321

priority_queue<value> que;
vector<value> vec[1001];
vector<int> dist;
int result[1001]{0,};
int n = 0, m = 0, x = 0;

void dijkstra(int i)
{
	dist.clear();
	dist.resize(n + 1, INF);

	dist[i] = 0;

	que.push(make_pair(0, i));

	while (!que.empty())
	{
		int w = -que.top().first;
		int v = que.top().second;
		que.pop();

		if (dist[v] < w)
			continue;

		for (int j = 0; j < vec[v].size(); ++j)
		{
			int _w = vec[v][j].first;
			int _u = vec[v][j].second;

			if (dist[v] + _w < dist[_u])
			{
				dist[_u] = dist[v] + _w;
				que.push(make_pair(-dist[_u], _u));
			}
		}
	}
}

int main()
{

	cin >> n >> m >> x;

	for (int i = 0; i < m; ++i)
	{
		int s = 0, e = 0, w = 0;

		cin >> s >> e >> w;

		vec[s].push_back(make_pair(w, e));
	}

	for (int i = 1; i <= n; ++i)
	{
		dijkstra(i);
		result[i] = dist[x];
	}

	dijkstra(x);

	for (int i = 1; i <= n; i++) result[i] = result[i] + dist[i];
	sort(result + 1, result + n + 1);

	cout << result[n] << endl;
	return 0;
}