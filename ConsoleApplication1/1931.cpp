#include "pch.h"

vector<pair<int, int>> vec;

int main()
{
	//1. 벡터에 값을 담는다.
	//2. 오름 차순으로 정렬한다.
	//3. 벡터에서 값을 빼, 큐에 담는다.
	//4. 큐에서 값을 빼, bfs를 돌린다.
	//5. 카운트를 버퍼에 담는다.
	int N{};
	int cnt{};
	cin >> N;
	for (int i{ 0 }; i < N; ++i)
	{
		int first, second;
		cin >> first >> second;
		vec.push_back(pair{ second, first });
	}

	sort(vec.begin(), vec.end());
	
	int time = vec[cnt].first;
	++cnt;

	for (int i{ 1 }; i < N; ++i)
	{
		if (vec[i].second >= time)
		{
			time = vec[i].first;
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}