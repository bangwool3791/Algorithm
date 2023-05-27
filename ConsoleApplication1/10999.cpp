#include "pch.h"

#define MAX 1'000'001
long long A[MAX];
long long Tree[MAX * 4];
long long Lazy[MAX * 4];

long long InitializeTree(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		return Tree[nodeIdx] = A[left];
	}

	int mid = (left + right) / 2;

	return Tree[nodeIdx] = (InitializeTree(left, mid, nodeIdx * 2) +  InitializeTree(mid + 1, right, nodeIdx * 2 + 1));
}

void Update_Lazy(int start, int end, int node)
{
	if (Lazy[node] != 0)
	{
		Tree[node] += (end - start + 1) * Lazy[node];

		if (start != end)
		{
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}
}

void Update(int left, int right, int start, int end, int nodeIdx, long long diff)
{
	Update_Lazy(left, right, nodeIdx);

	if (left > end || right < start)
	{
		return;
	}

	if (start <= left && right <= end)
	{
		Tree[nodeIdx] += (right - left + 1) * diff;

		if (left != right)
		{
			Lazy[nodeIdx * 2] += diff;
			Lazy[nodeIdx * 2 + 1] += diff;
		}
		return;
	}

	int mid = (left + right) / 2;

	Update(left, mid, start, end, nodeIdx * 2, diff);
	Update(mid + 1, right, start, end, nodeIdx * 2 + 1, diff);
	Tree[nodeIdx] = Tree[nodeIdx * 2] + Tree[nodeIdx *2 + 1];
}

long long Query(int left, int right, int start, int end, int nodeIdx)
{
	Update_Lazy(left, right, nodeIdx);

	if (left > end || right < start)
	{
		return 0;
	}

	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;

	return Query(left, mid, start, end, nodeIdx * 2) + Query(mid + 1, right, start, end, nodeIdx * 2 + 1);
}

int main()
{
	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}

	InitializeTree(1, n, 1);

	for (int i = 1; i <= m + k; ++i)
	{
		int a, b, c;
		long long d;

		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			Update(1, n, b, c, 1, d);
		}
		else
		{
			cin >> b >> c;
			cout << Query(1, n, b, c, 1) << '\n';
		}

	}
	return 0;
}