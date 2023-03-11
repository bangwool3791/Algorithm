#include "pch.h"

long long* tree;
long long arr[1000001];

long long init(int node, int start, int end)
{
	//리프노드이면 배열의 값 대입
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int sum(int start, int end, int node, int left, int right)
{
	//범위 밖에 있는 경우
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int diff)
{
	if (index < start || index > end) return;

	tree[node] += diff;

	if (start == end) return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num, m, k, a, b;
	long long c;
	cin >> num >> m >> k;
	int height = ceil(log2(num));
	tree = new long long[1 << (height + 1)];
	for (int i = 0; i < num; ++i)
		cin >> arr[i];

	init(1, 0, num - 1);

	for (int i = 0; i < m + k; ++i)
	{
		cin >> a >> b >> c;

		if (a == 1)
		{
			long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			update(1, 0, num - 1, b - 1, diff);
		}
		else if (a == 2)
			cout << sum(1, 0, num - 1, b - 1, c - 1) << endl;
	}
	return 0;
}