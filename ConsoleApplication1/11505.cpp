#include "pch.h"
#include <algorithm>
#include <iostream>

using namespace std;

const int MOD = 1000000007;
#define INF 987654321
#define MAX 1000001

long long arr[MAX];
long long node[MAX * 4];

long long initializeSegment(int first, int last, int idx)
{
	if (first == last)
	{
		return node[idx] = arr[last];
	}

	int mid = (first + last) / 2;

	return node[idx] = (initializeSegment(first, mid, idx * 2) * initializeSegment(mid + 1, last, idx * 2 + 1)) % MOD;
}

long long query(int first, int last, int idx, int firstNode, int lastNode)
{
	if (lastNode < first || firstNode > last)
		return 1;

	if (firstNode >= first && lastNode <= last)
	{
		return node[idx];
	}

	int mid = (firstNode + lastNode) / 2;

	return (query(first, last, idx * 2, firstNode, mid) * query(first, last, idx * 2 + 1, mid + 1, lastNode)) % MOD;
}

long long update(int nodeidx, int first, int last, int idx, long long val)
{
	if (idx < first || idx > last)
	{
		return node[nodeidx];
	}

	if (first == last)
		return  node[nodeidx] = val;

	int mid = (first + last) / 2;

	return node[nodeidx] = (update(nodeidx * 2, first, mid, idx, val) * update(nodeidx * 2 + 1, mid + 1, last, idx, val)) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}

	initializeSegment(1, N, 1);

	for (int i = 0; i < M + K; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			update(1, 1, N, b, c);
		}
		else
		{
			cout << query(b, c, 1, 1, N) << "\n";
		}
	}
	return 0;
}