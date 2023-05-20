#include "pch.h"

#define MAX 1'000'001

long long P[MAX];
long long Tree[MAX * 4];

long long InitSegment(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		return Tree[nodeIdx] = P[left];
	}

	int mid = (left + right) / 2;

	return Tree[nodeIdx] = (InitSegment(left, mid, nodeIdx * 2) + InitSegment(mid + 1, right, nodeIdx * 2 + 1));
}

void Update(int left, int right, int nodeIdx, int Idx, long long value)
{
	if (Idx < left || Idx > right)
	{
		return;
	}

	Tree[nodeIdx] += value;

	if (left == right)
		return;

	if (left != right)
	{
		int mid = (left + right) / 2;

		Update(left, mid, nodeIdx * 2, Idx, value);
		Update(mid + 1, right, nodeIdx * 2 + 1, Idx, value);
	}
}

long long Query(int left, int right, int nodeIdx, int start, int end)
{
	if (left > end || right < start)
	{
		return 0;
	}

	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;

	return Query(left, mid, nodeIdx * 2, start, end) + Query(mid + 1, right, nodeIdx * 2 + 1, start, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, Q;

	cin >> N >> Q;

	for (int i = 1; i <= Q; ++i)
	{
		long long a, b, c;

		cin >> a >> b >> c;

		if (a == 1)
		{
			Update(1, N, 1, b, c);
			P[b] = c;
		}
		else
		{
			cout << Query(1, N, 1, b, c) << '\n';
		}
	}
	return 0;
}
