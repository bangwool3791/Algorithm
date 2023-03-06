#include "pch.h"

vector<int> v[101];
bool bCheck[101][101];

int n = 0, m = 0;

void dfs(int n, int t)
{
	queue<pair<int, int>> que;
	que.push({0, n});

	while (!que.empty())
	{
		int d = que.front().first;
		int _n = que.front().second;
		que.pop();
		if (_n == t)
		{
			cout << d << endl;
			return;
		}

		for (int i = 0; i < v[_n].size(); ++i)
		{
			if (!bCheck[_n][i])
			{
				bCheck[_n][i] = true;
				que.push({ d + 1, v[_n][i] });
			}
		}
	}

	cout << -1 << endl;
}
int main()
{
	int a = 0, b = 0;
	cin >> a;
	cin >> n >> m;
	cin >> b;

	int c = 0, d = 0;

	for (int i = 0; i < b; ++i)
	{
		cin >> c >> d;
		v[c].push_back(d);
		v[d].push_back(c);
	}
	
	dfs(n, m);
	return 0;
}