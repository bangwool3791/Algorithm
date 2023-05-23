#include "pch.h"
#define INF 1'000'000'001

#define MAX 500'000

vector<pair<long long, int>> A;
long long Tree[MAX * 4];

void UpdateTree(int left, int right, int nodeIdx, int Idx)
{
	if (left == right)
	{
		 Tree[nodeIdx] = 1;
		 return;
	}

	int mid = (left + right) / 2;

	if (Idx <= mid) UpdateTree(left, mid, nodeIdx * 2, Idx);
	else if(Idx > mid) UpdateTree(mid + 1, right, nodeIdx * 2 + 1, Idx);
	Tree[nodeIdx] = Tree[nodeIdx * 2] + Tree[nodeIdx * 2 + 1];
}

long long cntLess(int nodeIdx, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;

	return cntLess(nodeIdx * 2, start, end, left, mid) + cntLess(nodeIdx * 2 + 1, start, end, mid + 1, right);
}

int main()
{
	int n = 0;
	long long ans = 0;
	cin >> n;

	A.resize(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin(), A.end());

	for (int i = 1; i <= n; ++i)
	{
		UpdateTree(1, n, 1, A[i].second);
		ans += cntLess(1, A[i].second + 1, n, 1, n);
	}

	cout << ans << '\n';
	return 0;
}