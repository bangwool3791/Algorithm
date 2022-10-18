#include "pch.h"

vector<pair<int, int>> vec;
vector<vector<int>>	   cnt;
int	  N = 0;
int   num = 0;

void bfs(pair<int, int> n)
{
	if (num == N - 1)
		return;

	queue<pair<int, int>> que;
	que.push(n);

	while (!que.empty())
	{
		pair<int, int> value = que.front();
		que.pop();

		for (int i{ 0 }; i < N; ++i)
		{
			if (value.second < vec[i].first)
			{
				cnt[num][i]++;
				//cnt 체크하는 부분 확인 필요
				que.push(vec[i]);
			}
		}
	}
	bfs(vec[++num]);
}
int main()
{
	//1. 벡터에 값을 담는다.
	//2. 오름 차순으로 정렬한다.
	//3. 벡터에서 값을 빼, 큐에 담는다.
	//4. 큐에서 값을 빼, bfs를 돌린다.
	//5. 카운트를 버퍼에 담는다.
	
	cin >> N;
	for (int i{ 0 }; i < N; ++i)
	{
		int first, second;
		cin >> first >> second;
		vec.push_back(pair{ first, second });
	}
	
	cnt.resize(N);

	for (int i{ 0 }; i < N; ++i)
	{
		cnt[i].resize(N);
	}

	bfs(vec[num]);

	int max{ 0 };
	for (int i{ 0 }; i < N; ++i)
	{
		for (int j{ 0 }; j < N; ++j)
		{
			if (max < cnt[i][j])
			{
				max = cnt[i][j];
			}
		}
	}
	return 0;
}