#include "pch.h"

#define MAX 500'001

vector<long long> Tree;

void Update(int left, int right, int idx, int nodeIdx)
{
	if (idx < left || idx > right)
	{
		return;
	}

	Tree[nodeIdx] += 1;

	if (left == right)
		return;

	int mid = (left + right) / 2.f;

	Update(left, mid, idx, nodeIdx * 2);
	Update(mid + 1, right, idx, nodeIdx * 2 + 1);
}

long long Query(int left, int right, int end, int nodeIdx)
{
	int start = 1;

	if (left > end || right < start) return 0;

	if (start <= left && right <= end) return Tree[nodeIdx];

	int mid = (left + right) / 2;

	return Query(left, mid, end, nodeIdx * 2) + Query(mid + 1, right, end, nodeIdx * 2 + 1);
}

int main()
{
	Tree.resize(MAX * 4);

	vector<long long> vecIdx;
	vecIdx.resize(MAX);
	vector<long long> answer;
	answer.resize(MAX);

	map<long long, int> index_set;
	int n = 0;

	cin >> n;

	vecIdx[0] = 1'000'000'001;

	for (int i = 1; i <= n; ++i)
	{
		cin >> vecIdx[i];
		index_set.insert(make_pair(vecIdx[i], i));
	}

	sort(vecIdx.begin(), vecIdx.end(), greater<long long>());

	for (int i = 1; i <= n; ++i)
	{
		int rank = index_set[vecIdx[i]];
		answer[rank] = Query(1, n, rank - 1, 1) + 1;
		Update(1, n, rank, 1);
	}
	
	for (int i = 1; i <= n; ++i)
		cout << answer[i] << '\n';
	return 0;
}