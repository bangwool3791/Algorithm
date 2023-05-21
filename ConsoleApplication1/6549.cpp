#include "pch.h"

#define MAX 100'001
#define INF 1'000'000'001

long long n;
long long ans;

long long h[MAX];
long long Tree[MAX * 4];

long long InitalizeTree(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		return Tree[nodeIdx] = left;
	}

	int mid = (left + right) / 2;

	long long leftIdx = InitalizeTree(left, mid, nodeIdx * 2);
	long long rightIdx = InitalizeTree(mid + 1, right, nodeIdx * 2 + 1);

	return Tree[nodeIdx] = h[leftIdx] < h[rightIdx] ? leftIdx : rightIdx;
}

long long Query(int left, int right, int nodeIdx, int start, int end)
{
	if (left > end || right < start)
		return INF;

	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;

	long long leftIdx = Query(left, mid, nodeIdx * 2, start, end);
	long long rightIdx = Query(mid + 1, right, nodeIdx * 2 + 1, start, end);

	if (leftIdx == INF)return rightIdx;
	else if (rightIdx == INF)return leftIdx;
	else return Tree[nodeIdx] = h[leftIdx] < h[rightIdx] ? leftIdx : rightIdx;
}

void Solve(int left, int right)
{
	if (left > right)
	{
		return;
	}

	int index = Query(1, n, 1, left, right);

	ans = max(ans, (right - left + 1) * h[index]);

	Solve(left, index - 1);
	Solve(index + 1, right);
}

int main()
{
	while (1)
	{
		ans = 0;
		cin >> n;
		if (n == 0) break;

		for (int i = 1; i <= n; i++)
		{
			cin >> h[i];
		}
		InitalizeTree(1, n, 1); // 세그먼트 트리 만들기
		Solve(1, n);

		cout << ans << endl;
	}

	return 0;
}