#include "pch.h"

#define INF 987654321

#define T pair<int, int>
priority_queue<T, vector<T>, greater<T>> que;
vector<int> v[300001];
int dist[300001];

int n = 0, m = 0, k = 0, x = 0;

void dijkstra()
{
	que.push({ 0, x });
	dist[x] = 0;

	while (!que.empty())
	{
		int _w = que.top().first;
		int _v = que.top().second;
		que.pop();

		if (dist[_v] < _w)
			continue;

		for (int i = 0; i < v[_v].size(); ++i)
		{
			int __v = v[_v][i];

			if (dist[_v] + 1 < dist[__v])
			{
				dist[__v] = dist[_v] + 1;
				que.push({ dist[__v], __v });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k >> x;

	for (int i = 1; i <= n; ++i)
		dist[i] = INF;

	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[a].push_back(b);
	}

	dijkstra();

	vector<int> answer;
	for (int i = 1; i <= n; ++i)
	{
		if (k == dist[i])
			answer.push_back(i);
	}

	sort(answer.begin(), answer.end());

	if (0 < answer.size())
	{
		for (int i = 0; i < answer.size(); ++i)
		{
			cout << answer[i] << endl;
		}
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}