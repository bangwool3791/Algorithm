#include "pch.h"

#define MAX 100001

vector<long long> tree;
vector<int> sum_arr;
vector<int> arr;

long long Initialize(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		return tree[nodeIdx] = sum_arr[left];
	}
	int mid = (left + right) / 2;

	return  tree[nodeIdx] = Initialize(left, mid, nodeIdx * 2) + Initialize(mid + 1, right, nodeIdx * 2 + 1);
}

long long Update(int left, int right, int nodeIdx, int value, int target)
{
	if (target < left || target > right)
	{
		return tree[nodeIdx];
	}

	if (left == right)
	{
		return tree[nodeIdx] = value;
	}

	int mid = (left + right) / 2;

	return tree[nodeIdx] = Update(left, mid, nodeIdx * 2, value, target) + Update(mid + 1, right, nodeIdx * 2 + 1, value, target);

}

long long Query(int left, int right, int nodeIdx, int start, int end)
{
	if (right < start || left > end) return 0;

	if (start <= left && right <= end)
		return tree[nodeIdx];

	int mid = (left + right) / 2;

	return Query(left, mid, nodeIdx * 2, start, end) + Query(mid + 1, right, nodeIdx * 2 + 1, start, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 0;
	cin >> t;

	int idx = 0;

	for (int i = 0; i < t; ++i)
	{
		int n, m = 0;
		cin >> n >> m;
		idx = m;
		int lmax = n + m;
		tree.clear();
		sum_arr.clear();
		arr.clear();

		tree.resize(MAX * 6);
		sum_arr.resize(MAX  * 2);
		arr.resize(MAX);

		for (int i = 1; i <= n; ++i)
		{
			arr[i] = i + m;

			sum_arr[m + i] = 1;
		}

		Initialize(1, lmax, 1);

		for (int i = 1; i <= m; ++i)
		{
			int temp;
			cin >> temp;

			cout << Query(1, lmax, 1, idx, arr[temp] - 1) << ' ';
			Update(1, lmax, 1, 0, arr[temp]);
			Update(1, lmax, 1, 1, idx);
			arr[temp] = idx;
			idx--;
		}
		cout << '\n';
	}
	return 0;
}