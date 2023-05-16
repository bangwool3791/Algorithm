#include "pch.h"

#define MAX 1'000'001

long long arr[MAX];
long long node[MAX * 4];

long long Sum(int left, int right, int nodeIdx, int NodeLeft, int NodeRight)
{
	if (NodeRight < left || NodeLeft > right)
		return 0;

	if (left <= NodeLeft && NodeRight <= right)
	{
		return node[nodeIdx];
	}

	int mid = (NodeLeft + NodeRight) / 2;

	return (Sum(left, right, nodeIdx * 2, NodeLeft, mid) + Sum(left, right, nodeIdx * 2 + 1, mid + 1, NodeRight));
}

long long Modify(int nodeIdx, int left, int right, int Idx, long long value)
{

	if (left > Idx || Idx > right)
	{
		return node[nodeIdx];
	}

	if (left == right)
	{
		return node[nodeIdx] = value;
	}

	int mid = (left + right) / 2;

	return node[nodeIdx] = (Modify(nodeIdx * 2, left, mid, Idx, value) + Modify(nodeIdx * 2 + 1, mid + 1, right, Idx, value));
}

int main()
{
	memset(arr, 0, sizeof(long long) * MAX);
	memset(node, 0, sizeof(long long) * MAX * 4);

	int N = 0, M = 0;
	
	cin >> N >> M;

	for (int i = 1; i <= M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0)
		{
			if (b > c) swap(b, c);
			cout << Sum(b, c, 1, 1, N) << '\n';
		}
		else
		{

			Modify(1, 1, N, b, c);
		}
	}
	return 0;
}