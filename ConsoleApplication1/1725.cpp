#include "pch.h"

#define MAX 100'000
#define INF 1'000'000'000

long long h[MAX];
long long Tree[MAX * 4];

int n;
long long ans;

long long initializeTree(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		return Tree[nodeIdx] = left;
	}

	int mid = (left + right) / 2;

	int leftIdx = initializeTree(left, mid, nodeIdx * 2);
	int rightIdx = initializeTree(mid + 1, right, nodeIdx * 2 + 1);
	return Tree[nodeIdx] = h[leftIdx] < h[rightIdx] ? leftIdx : rightIdx;
}

long long Query(int left, int right, int start, int end, int nodeIdx)
{
	if (end < left || right < start)
	{
		return INF;
	}

	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;

	int leftIdx = Query(left, mid, start, end, nodeIdx * 2);
	int rightIdx = Query(mid + 1, right, start, end, nodeIdx * 2 + 1);

	if (leftIdx == INF)return rightIdx;
	else if (rightIdx == INF)return leftIdx;
	else return h[leftIdx] < h[rightIdx] ? leftIdx : rightIdx;
}

void Solve(int left, int right)
{
	if (left > right)
	{
		return;
	}

	int index = Query(1, n, left, right, 1);

	ans = max(ans, (right - left + 1) * h[index]);

	Solve(left, index - 1);
	Solve(index + 1, right);
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> h[i];
	}

	initializeTree(1, n, 1);

	Solve(1, n);

	cout << ans << '\n';

	return 0;
}