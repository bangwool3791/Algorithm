#include "pch.h"

bool bCheck[100001];
queue<pair<int, int>> que;
int N = 0, K = 0;

void bfs(int v)
{

	que.push(make_pair(v, 0));

	while (!que.empty())
	{
		int dist = que.front().first;
		int cost = que.front().second;

		if (K == dist)
		{
			cout << cost << endl;
			return;
		}

		bCheck[dist] = true;
		que.pop();

		int dx1 = dist - 1;
		int dx2 = dist + 1;
		int dx3 = dist * 2;

		if (0 <= dx1 && dx1 < 100001 && !bCheck[dx1])
		{
			que.push(make_pair(dx1, cost + 1));
		}

		if (0 <= dx2 && dx2 < 100001 && !bCheck[dx2])
		{
			que.push(make_pair(dx2, cost + 1));
		}

		if (0 <= dx3 && dx3 < 100001 && !bCheck[dx3])
		{
			que.push(make_pair(dx3, cost + 1));
		}
	}
}
int main()
{

	cin >> N >> K;
	bfs(N);

	return 0;
}