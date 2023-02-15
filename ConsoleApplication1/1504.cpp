#include "pch.h"

#define INF 987654321
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
vector<vector<pair<int, int>>> vec;
vector<int> dist;

int n = 0;
int e = 0;
long long result1 = 0;
long long result2 = 0;

void bfs(int s)
{
	que.push(make_pair(0, s));
	dist[s] = 0;

	while (!que.empty())
	{
		int w = -que.top().first;
		int v = que.top().second;
		que.pop();

		if (dist[v] < w)continue;

		for (int i = 0; i < vec[v].size(); ++i)
		{
			int _w = vec[v][i].first;
			int _v = vec[v][i].second;

			if (dist[v] + _w < dist[_v])
			{
				dist[_v] = dist[v] + _w;
				que.push(make_pair(-dist[_v], _v));
			}
		}
	}
}
int main()
{
	dist.resize(801, INF);

	cin >> n >> e;
	
	vec.resize(n + 1);

	for (int i = 0; i < e; ++i)
	{
		int a = 0, b = 0, c = 0;

		cin >> a >> b >> c;

		vec[a].push_back(make_pair(c, b));
		vec[b].push_back(make_pair(c, a));
	}

	int s = 0, end = 0;

	cin >> s >> end;

	bfs(1);

	result1 = dist[s];
	result2 = dist[end];

	dist.clear();
	dist.resize(801, INF);
	
	bfs(s);

	result1 += dist[end];

	dist.clear();
	dist.resize(801, INF);

	bfs(end);

	result2 += dist[s];

	dist.clear();
	dist.resize(801, INF);

	bfs(end);

	result1 += dist[n];

	dist.clear();
	dist.resize(801, INF);

	bfs(s);

	result2 += dist[n];

	if (INF <= result1 && INF <= result2)
		cout << -1 << endl;
	else if (result1 < result2)
		cout << result1;
	else
		cout << result2;
	
	return 0;
}