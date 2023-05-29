#include "pch.h"

#define MAX 1'000'001

vector<long long> A;
vector<long long> Tree;
vector<long long> LazyTree;

long long InitTree(int left, int right, int nodeIdx)
{
	if (left == right)
		return Tree[nodeIdx] = A[left];

	int mid = (left + right) / 2;

	return Tree[nodeIdx] = InitTree(left, mid, nodeIdx * 2) + InitTree(mid + 1, right, nodeIdx * 2 + 1);
}

void LazyUpdate(int left, int right, int nodeIdx)
{
	if (LazyTree[nodeIdx] != 0)
	{
		Tree[nodeIdx] += (right - left + 1) * LazyTree[nodeIdx];
		
		if (left != right)
		{
			LazyTree[nodeIdx * 2] += LazyTree[nodeIdx];
			LazyTree[nodeIdx * 2 + 1] += LazyTree[nodeIdx];
		}

		LazyTree[nodeIdx] = 0;
	}
}

long long Query(int left, int right, int nodeIdx, int start, int end)
{
	LazyUpdate(left, right, nodeIdx);

	if (left > end || right < start)
		return 0;


	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;

	return Query(left, mid, nodeIdx * 2, start, end) + Query(mid + 1, right, nodeIdx * 2 + 1, start, end);
}

void Update(int left, int right, int nodeIdx, int start, int end, long long diff)
{
	LazyUpdate(left, right, nodeIdx);

	if (left > end || right < start)
		return;

	if (start <= left && right <= end)
	{
		Tree[nodeIdx] += (right - left + 1) * diff;

		if (left != right)
		{
			LazyTree[nodeIdx * 2] += diff;
			LazyTree[nodeIdx * 2 + 1] += diff;
		}

		return;
	}

	int mid = (left + right) / 2.f;

	Update(left, mid, nodeIdx * 2, start, end, diff);
	Update(mid + 1, right, nodeIdx * 2 + 1, start, end, diff);
	Tree[nodeIdx] = Tree[nodeIdx * 2] + Tree[nodeIdx * 2 + 1];
}

int main()
{
	A.resize(MAX);
	LazyTree.resize(MAX * 4);
	Tree.resize(MAX * 4);

	long long n, m, k;

	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		cin >> A[i];

	InitTree(1, n, 1);

	for (int i = 1; i <= m + k; ++i)
	{
		long long a, b, c;
		long long d;
		
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			Update(1, n, 1, b, c, d);
		}
		else
		{
			cin >> b >> c;
			cout << Query(1, n, 1, b, c) << '\n';
		}
	}
	return 0;
}