#include "pch.h"

#define MAX 500'001

long long Tree[MAX * 4];
bool memozation[MAX];

vector<long long> A;
vector<long long> B;

long long ans = 0;

long long Sum(int left, int right, int nodeIdx, int start, int end)
{
	if (left > end || right < start)
	{
		return 0;
	}

	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) * 0.5f;
	return (Sum(left, mid, nodeIdx * 2, start, end) + Sum(mid + 1, right, nodeIdx * 2 + 1, start, end));
}

void Update(int left, int right, int nodeIdx, int idx, long long value)
{
	if (idx < left || idx > right)
		return;

	Tree[nodeIdx] += value;

	if (left != right)
	{
		int mid = (left + right) * 0.5f;
		Update(left, mid, nodeIdx * 2, idx, value);
		Update(mid + 1, right, nodeIdx * 2 + 1, idx, value);
	}
}

int main()
{
	int n = 0;

	cin >> n;

	A.resize(1'000'001);
	B.resize(1'000'001);

	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		B[a] = i;
	}

	for (int i = 1; i <= n; ++i)
	{
		int start = B[A[i]];
		ans += Sum(1, n, 1, start + 1, n);
		Update(1, n, 1, start, 1);
	}

	cout << ans << '\n';

	return 0;
}
