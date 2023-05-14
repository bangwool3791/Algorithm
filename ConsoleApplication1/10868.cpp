#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;
const int INF = 1e9 + 1;

long long arr[MAX];
long long segmentTree[4 * MAX];

long long initalizeSegment(int left, int right, int node)
{
	if (left == right)
	{
		segmentTree[node] = arr[left];
	}

	int mid = (left + right) / 2;

	return segmentTree[node] = min(initalizeSegment(left, mid, node * 2), initalizeSegment(mid + 1, right, node * 2 + 1));
}

long long query(int left, int right, int node, int leftnode, int rightnode)
{
	if (left > rightnode || right < leftnode)
	{
		return INF;
	}

	if (leftnode >= left && rightnode <= right)
	{
		return segmentTree[node];
	}

	int mid = (leftnode + rightnode) / 2;

	return min(query(left, right, node * 2, leftnode, mid), query(left, right, node * 2 + 1, mid + 1, rightnode));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}


	initalizeSegment(1, N, 1);

	for (int i = 1; i <= M; ++i)
	{
		int a, b;

		cin >> a >> b;

		cout << query(a, b, 1, 1, N) << "\n";
	}

	return 0;
}