#include "pch.h"

#define INF 987654321

int k = 0;
int n = 0;
int cnt = INF;

int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };

bool dp[301][301];

int sx = 0;
int sy = 0;
int tx = 0;
int ty = 0;

vector<int> answer;

void print()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << dp[i][j] <<  " ";
		}
		cout << endl;
	}
}

void clear()
{
	for (int i = 0; i < 301; ++i)
	{
		for (int j = 0; j < 301; ++j)
		{
			dp[i][j] = false;
		}
	}

}
void bfs(int x, int y)
{
	queue<pair<int ,pair<int, int>>> que;
	//말이 놓인 초기 위치는 이동 회수가 아님
	que.push({ 0, {x,y} });
	dp[y][x] = true;

	while (!que.empty())
	{
		int w = que.front().first;
		int _x = que.front().second.first;
		int _y = que.front().second.second;

		que.pop();

		if (tx == _x && ty == _y)
		{
			if (w < cnt)
				cnt = w;
		}


		for (int i = 0; i < 8; ++i)
		{
			int __x = _x + dx[i];
			int __y = _y + dy[i];

			if (-1 < __x && __x < n && -1 < __y && __y < n)
			{
				if (!dp[__y][__x])
				{
					dp[__y][__x] = true;
					que.push({ w + 1,  {__x,__y}});
				}
			}
		}
	}

}
int main()
{
	clear();

	cin >> k;

	while (k--)
	{
		cin >> n >> sx >>sy >> tx >> ty;

		bfs(sx, sy);

		answer.push_back(cnt);
		cnt = INF;
		clear();
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

	return 0;
}