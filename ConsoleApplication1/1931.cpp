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
				//cnt üũ�ϴ� �κ� Ȯ�� �ʿ�
				que.push(vec[i]);
			}
		}
	}
	bfs(vec[++num]);
}
int main()
{
	//1. ���Ϳ� ���� ��´�.
	//2. ���� �������� �����Ѵ�.
	//3. ���Ϳ��� ���� ��, ť�� ��´�.
	//4. ť���� ���� ��, bfs�� ������.
	//5. ī��Ʈ�� ���ۿ� ��´�.
	
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