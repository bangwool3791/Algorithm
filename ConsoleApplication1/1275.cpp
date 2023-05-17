#include "pch.h"

#define MAX 100'001

long long arr[MAX];
long long node[MAX * 4];

long long initializeNode(int nodeIdx, int leftNode, int rightNode)
{
	if (leftNode == rightNode)
	{
		return node[nodeIdx] = arr[leftNode];
	}

	int mid = (leftNode + rightNode) / 2;

	return node[nodeIdx] = (initializeNode(nodeIdx * 2, leftNode, mid) + initializeNode(nodeIdx * 2 + 1, mid + 1, rightNode));
}

long long Sum(int nodeIdx, int left, int right, int leftNode, int rightNode)
{
	if (rightNode < left || leftNode > right)
		return 0;

	if (left <= leftNode && rightNode <= right)
		return node[nodeIdx];

	int mid = (leftNode + rightNode) / 2;

	return (Sum(nodeIdx * 2, left, right, leftNode, mid) + Sum(nodeIdx * 2 + 1, left, right, mid + 1, rightNode));
}

void Update(int nodeIdx, int left, int right, int Idx, long long value)
{
	if (Idx < left || right < Idx)
		return;

	node[nodeIdx] += value;

	if (left != right)
	{
		int mid = (left + right) / 2;

		Update(nodeIdx * 2, left, mid, Idx, value);
		Update(nodeIdx * 2 + 1, mid + 1, right, Idx, value);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	initializeNode(1, 1, N);

	for (int i = 1; i <= Q; ++i)
	{
		int x, y;
		long long a, b;

		cin >> x >> y >> a >> b;

		if (x > y)swap(x, y);

		cout << Sum(1, x, y, 1, N) << '\n';
		Update(1, 1, N, a, b - arr[a]);
		arr[a] = b;
	}
	return 0;
}