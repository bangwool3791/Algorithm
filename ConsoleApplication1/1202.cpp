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
	* i번째 가방
	* i번째 가방이 담을 수 있는 보석은 다 담는다.
	* 그 중 가장 큰 가격의 보석을 답에 추가.
	* 큐삭제
	*/

	priority_queue<int> que;
	int idx = 0;

	for (int i = 0; i < K; ++i)
	{
		/*
		* 오름 차순 정리
		* 가방 보다 무게가 작은 쥬얼리가 있다면
		* 반복문 순회
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