#include "pch.h"

#define MAX 1'000'001

long long A[MAX];
long long Tree[MAX * 4];

long long Query(int nodeIdx, int left, int right, int cnt)
{
	if (left == right)
		return right;

	int mid = (left + right) / 2;

	if (Tree[nodeIdx * 2] < cnt) return Query(nodeIdx * 2 + 1, mid + 1, right, cnt - Tree[nodeIdx * 2]);
	else return Query(nodeIdx * 2, left, mid, cnt);
}

void Update(int nodeIdx, int start, int end, int idx, long long value)
{
	if (idx < start || idx > end)
		return;

	if (start == end)
	{
		Tree[nodeIdx] = value;
		return;
	}

	int mid = (start + end) / 2;

	Update(nodeIdx * 2, start, mid, idx, value);
	Update(nodeIdx * 2 + 1, mid + 1, end, idx, value);
	Tree[nodeIdx] = Tree[nodeIdx * 2] + Tree[nodeIdx * 2 + 1];

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		long long a, b, c;
		cin >> a;

		if (a == 1)
		{
			cin >> b;
			long long k = Query(1, 1, MAX, b);
			cout << k << '\n';
			Update(1, 1, MAX, k, A[k] - 1);
			A[k] -= 1;
		}
		else
		{
			cin >> b >> c;
			Update(1, 1, MAX, b, A[b] + c);
			A[b] += c;
		}
	}
	return 0;
}