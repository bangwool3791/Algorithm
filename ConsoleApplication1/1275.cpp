#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

long long arr[MAX];
long long node[MAX * 4];

long long initSegment(int nodeIdx, int start, int end)
{
	if (start == end) return node[nodeIdx] = arr[end];
	int mid = (start + end) / 2;
	return node[nodeIdx] = initSegment(2 * nodeIdx, start, mid) + initSegment(2 * nodeIdx + 1, mid + 1, end);
}

long long query(int left, int right, int nodeIdx, int leftNode, int rightNode)
{
	if (rightNode < left || leftNode > right)
	{
		return 0;
	}

	if (leftNode >= left && rightNode <= right)
	{
		return node[nodeIdx];
	}

	int mid = (leftNode + rightNode) / 2;

	return (query(left, right, nodeIdx * 2, leftNode, mid) + query(left, right, nodeIdx * 2 + 1, mid + 1, rightNode));
}

void update(int ndoeidx, int start, int end, int idx, long long diff) {
	if (idx < start || idx > end) return;
	node[ndoeidx] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(2 * ndoeidx, start, mid, idx, diff);
		update(2 * ndoeidx + 1, mid + 1, end, idx, diff);
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
	{
		cin >> arr[i];
	}

	initSegment(1, 1, N);

	for (int i = 1; i <= Q; ++i)
	{
		int x, y;

		long long a, b;
		cin >> x >> y >> a >> b;

		if (x > y) swap(x, y);

		cout << query(x, y, 1, 1, N) << "\n";
		update(1, 1, N, a, b - arr[a]);
	}

	return 0;
}