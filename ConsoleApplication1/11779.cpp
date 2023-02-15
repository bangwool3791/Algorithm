#include "pch.h"

#define INF 987654321

#define pair pair<int, int>
priority_queue<pair, vector<pair>, greater<pair>> que;
vector<pair> v[1001];
int dist[1001];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n = 0, m = 0;
int source = 0, dest = 0;

int route[1001];

void dijkstra(int idx)
{
	que.push({ 0, idx });
	dist[idx] = 0;
	
	while (!que.empty())
	{
		int _w = que.top().first;
		int _v = que.top().second;
		que.pop();

		if (dist[_v] < _w)
			continue;

		for (int i = 0; i < v[_v].size(); ++i)
		{
			int __w = v[_v][i].first;
			int __v = v[_v][i].second;

			if (dist[_v] + __w < dist[__v])
			{
				/*
				* route[_v] = __v;
				* 이면 dest 정점 가중치 INF이므로 모든 dest가 _v와 매칭
				* route[__v] = _v;
				* 이면 dest 정점 입장에서 가중치가 적은 정점만 매칭
				*/
				route[__v] = _v;
				dist[__v] = dist[_v] + __w;
				que.push({ dist[__v], __v });
			}
		}
	}
}

void dfs()
{
	
}

void clear()
{
	for (int i = 1; i <= n; ++i)
		dist[i] = INF;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
	}

	cin >> source >> dest;
	clear();
	dijkstra(source);

	cout << dist[dest] << endl;
	int idx = dest;

	stack<int> answer{};
	while (idx)
	{
		answer.push(idx);
		idx = route[idx];
	}

	cout << answer.size() << endl;

	while(!answer.empty())
	{
		int a = answer.top();
		cout << a << " ";
		answer.pop();
	}

	return 0;
}