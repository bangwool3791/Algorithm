#include "pch.h"

const long long INF = 1'000'000'001;

#define MAX 100'001

long long A[MAX];
long long Tree[MAX * 4];

long long InitializeTree(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		return A[nodeIdx] = Tree[left];
	}

	int mid = (left + right) / 2;

	return A[nodeIdx] = min(InitializeTree(left, mid, nodeIdx * 2), InitializeTree(mid + 1, right, nodeIdx * 2 + 1));
}

long long Update(int start, int end, int nodeIdx, int idx, long long value)
{
	if (idx < start || idx > end)
		return A[nodeIdx];

	if (start != end)
	{
		int mid = (start + end) / 2;

		return A[nodeIdx] = min(Update(start, mid, nodeIdx * 2, idx, value), Update(mid + 1, end, nodeIdx * 2 + 1, idx, value));
	}
	else
	{
		return A[nodeIdx] = value;
	}	
}

long long Query(int start, int end, int nodeIdx, int left, int right)
{
	if (left > end || right < start)
		return INF;

	if (start <= left && right <= end)
	{
		return A[nodeIdx];
	}

	int mid = (left + right) / 2;

	return min(Query(start, end, nodeIdx * 2, left, mid), Query(start, end, nodeIdx * 2 + 1, mid + 1, right));
}

void main()
{
	int N, M;

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
	}

	cin >> M;

	for (int i = 1; i < M; ++i)
	{
		int a, b;
		long long c;

		cin >> a >> b >> c;

		if (a == 1)
		{
			Update(1, N, 1, b, c);
		}
		else
		{
			cout << Query(b, c, 1, 1, N) << '\n';
		}
	}
	return 0;
}