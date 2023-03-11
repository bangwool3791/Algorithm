#include "pch.h"

#define MAX 300001

pair<int, int> jewerly[MAX];
int bag[MAX];
int N, K;
int answer = 0;

int main()
{
	cin >> N >> K;

	int M, V;

	for (int i = 0; i < N; ++i)
	{
		cin >> M >> V;

		jewerly[i] = {M, V};
	}

	int C;

	for (int i = 0; i < K; ++i)
	{
		cin >> C;
		bag[i] = C;
	}

	sort(jewerly, jewerly + N);
	sort(bag, bag + K);
	/*
	* i��° ����
	* i��° ������ ���� �� �ִ� ������ �� ��´�.
	* �� �� ���� ū ������ ������ �信 �߰�.
	* ť����
	*/

	priority_queue<int> que;
	int idx = 0;

	for (int i = 0; i < K; ++i)
	{
		/*
		* ���� ���� ����
		* ���� ���� ���԰� ���� ��󸮰� �ִٸ�
		* �ݺ��� ��ȸ
		*/

		while (idx < N && bag[i] >= jewerly[idx].first)
		{
			que.push(jewerly[idx].second);
			++idx;
		}

		if (!que.empty())
		{
			answer += que.top();
			que.pop();
		}
	}
	cout << answer << endl;
	return 0;
}