#include "pch.h"

const long long INF = 100'000'0001;
#define MAX 100'001

long long A[MAX];
long long Tree[MAX * 4];

long long initializeSegment(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		return Tree[nodeIdx] = A[left];
	}

	int mid = (left + right) / 2;

	return Tree[nodeIdx] = min(initializeSegment(left, mid, nodeIdx * 2), initializeSegment(mid + 1, right, nodeIdx * 2 + 1));
}

long long Update(int left, int right, int nodeIdx, int Idx, long long value)
{
	if (Idx < left || Idx > right)
		return Tree[nodeIdx];

	if (left != right)
	{
		int mid = (left + right) / 2;

		return Tree[nodeIdx] = min(Update(left, mid, nodeIdx * 2, Idx, value), Update(mid + 1, right, nodeIdx * 2 + 1, Idx, value));
	}
	else
	{
		return Tree[nodeIdx] = value;
	}
}

long long Query(int left, int right, int nodeIdx, int leftNode, int rightNode)
{
	if (rightNode < left || leftNode > right)
		return INF;

	if (left <= leftNode && rightNode <= right)
	{
		return Tree[nodeIdx];
	}

	int mid = (leftNode + rightNode) / 2;

	return min(Query(left, right, nodeIdx * 2, leftNode, mid), Query(left, right, nodeIdx * 2 + 1, mid + 1, rightNode));
}

int main()
{
	int N, M;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
	}

	initializeSegment(1, N, 1);

	cin >> M;

	for (int i = 1; i <= M; ++i)
	{
		int a;
		long long b, c;

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