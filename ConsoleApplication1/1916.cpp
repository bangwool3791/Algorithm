#include "pch.h"

struct Edge
{
	int w;
	int to;
	Edge(int _w, int _to)
	{
		w = _w;
		to = _to;
	}
};

#define INF 987654321;

vector<Edge> vec[10001];
int dst[10001];

int main()
{
	int n = 0, m = 0;

	cin >> n >> m;

	for (int i = 0; i < 10001; ++i)
		dst[i] = INF;

	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		vec[a].push_back(Edge(c, b));
	}

	int s = 0, e = 0;

	cin >> s >> e;

	dst[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >que;

	que.push(make_pair(0, s));

	while (!que.empty())
	{
		int _w = que.top().first * -1;
		int _v = que.top().second;
		que.pop();

		if (dst[_v] < _w) continue;

		for (int i = 0; i < vec[_v].size(); ++i)
		{
			int _to = vec[_v][i].to;
			int _w2 = vec[_v][i].w;

			if (dst[_v] + _w2 < dst[_to])
			{
				dst[_to] = dst[_v] + _w2;
				que.push(make_pair(dst[_to] * -1, _to));
			}
		}
	}

	cout << dst[e] << endl;

	return 0;
}