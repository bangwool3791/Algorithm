#include "pch.h"

#define MAX 100001
bool bCheck[100001];
int n = 0, k = 0;

int main()
{
	cin >> n >> k;
	int result;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

	que.push(make_pair(0, n));

	while (!que.empty())
	{
		int w = que.top().first;
		int v = que.top().second;
		que.pop();

		bCheck[v] = true;

		if (v == k)
		{
			result = w;
			break;
		}

		if (v * 2 < MAX && !bCheck[v * 2])
		{
			que.push(make_pair(w, v * 2));
		}

		if (v + 1 < MAX && !bCheck[v + 1])
		{
			que.push(make_pair(w + 1, v + 1));
		}

		if (-1 < v - 1 && !bCheck[v - 1])
		{
			que.push(make_pair(w + 1, v - 1));
		}
	}

	cout << result << endl;
	return 0;

}