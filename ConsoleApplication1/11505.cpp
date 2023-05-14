#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 1;
#define MOD 1000000007
#define MAX 1000001
long long Arr[MAX];
long long Node[MAX * 4];

long long InitializeSeg(int left, int right, int node)
{
	if (left == right)
	{
		return Node[node] = Arr[left];
	}
	
	int mid = (left + right) / 2;
	return Node[node] = (InitializeSeg(left, mid, node * 2) * InitializeSeg(mid + 1, right, node * 2 + 1)) % MOD;
}

long long Query(int left, int right, int node, int leftnode, int rightnode)
{
	if (left > rightnode || right < leftnode)
		return 1;

	if (leftnode >= left && rightnode <= right)
		return Node[node];

	int mid = (leftnode + rightnode) / 2;

	return (Query(left, right, node * 2, leftnode, mid) * Query(left, right, node * 2 + 1, mid + 1, rightnode)) % MOD;
}

long long Update(int node, int start, int end, int idx, long long val)
{
	if (idx < start || idx > end) return Node[node];

	if (start == end)
		return Node[node] = val;
	
	int mid = (start + end) / 2;

	return Node[node] = (Update(node * 2, start, mid, idx, val) * Update(node * 2 + 1, mid + 1, end, idx, val)) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Arr[i];
	}

	InitializeSeg(1, N, 1);

	for (int i = 0; i < M + K; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		if (a == 1)
		{
			Update(1, 1, N, b, c);
		}
		else
		{
			cout << Query(b, c, 1, 1, N) << "\n";
		}
	}
	return 0;
}