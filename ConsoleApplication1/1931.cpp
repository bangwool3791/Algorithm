#include "pch.h"

vector<pair<int, int>> vec;

int main()
{
	//1. ���Ϳ� ���� ��´�.
	//2. ���� �������� �����Ѵ�.
	//3. ���Ϳ��� ���� ��, ť�� ��´�.
	//4. ť���� ���� ��, bfs�� ������.
	//5. ī��Ʈ�� ���ۿ� ��´�.
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