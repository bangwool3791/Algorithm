#include "pch.h"

#define MAX 500'001

long long A[MAX];
long long Tree[MAX * 4];

long long Init(int left, int right, int nodeIdx, int idx)
{
	if (idx < left || idx > right)
		return Tree[nodeIdx];

	if (left == right)
	{
		return Tree[nodeIdx] = 1;
	}

	int mid = (left + right) / 2;
	
	return Tree[nodeIdx] = Init(left, mid, nodeIdx * 2, idx) + Init(mid + 1, right, nodeIdx * 2 + 1, idx);
}

long long Less(int left, int right, int nodeIdx, int start, int end)
{
	if (start > right || end < left)
		return 0;

	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;

	return Less(left, mid, nodeIdx * 2, start, end) + Less(mid + 1, right, nodeIdx * 2 + 1, start, end);
}

long long ans = 0;

int main()
{
	int n = 0;
	cin >> n;

	vector<pair<long long, int>> A;
	A.resize(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin(), A.end());

	for (int i = 1; i <= n; ++i)
	{
		Init(1, n, 1, A[i].second);
		ans += Less(1, n, 1, A[i].second + 1, n);
	}
	cout << ans << '\n';
	return 0;
}