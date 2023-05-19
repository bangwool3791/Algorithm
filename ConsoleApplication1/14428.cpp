#include "pch.h"

#define INF 1000'000'001
#define MAX 100'001

long long A[MAX];
pair<long long, int> Tree[MAX * 4];

pair<long long, int> InitializeSegment(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		Tree[nodeIdx].first = A[left];
		Tree[nodeIdx].second = left;
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;
	pair<long long, int> leftNode = InitializeSegment(left, mid, nodeIdx * 2);
	pair<long long, int> rightNode = InitializeSegment(mid + 1, right, nodeIdx * 2 + 1);

	if (leftNode.first < rightNode.first)
		return Tree[nodeIdx] = leftNode;
	else if (leftNode.first > rightNode.first)
		return Tree[nodeIdx] = rightNode;
	else
	{
		if (leftNode.second < rightNode.second)
		{
			return Tree[nodeIdx] = leftNode;
		}
		else if (leftNode.second > rightNode.second)
		{
			return Tree[nodeIdx] = rightNode;
		}
	}
}

pair<long long, int> Query(int start, int end, int nodeIdx, int left, int right)
{
	if (left > end || right < start)
	{
		return pair<long long, int>(INF, -1);
	}

	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;
	
	pair<long long, int> leftNode = Query(start, end, nodeIdx * 2, left, mid);
	pair<long long, int> rightNode = Query(start, end, nodeIdx * 2 + 1, mid + 1, right);

	if (leftNode.first < rightNode.first)
	{
		return leftNode;
	}
	else if (leftNode.first > rightNode.first)
	{
		return rightNode;
	}
	else
	{
		if (leftNode.second < rightNode.second)
		{
			return leftNode;
		}
		else if (leftNode.second > rightNode.second)
		{
			return rightNode;
		}
	}
}

pair<long long, int> Update(int start, int end, int nodeIdx, int Idx, pair<long long, int> value)
{
	if (Idx < start || Idx > end)
	{
		return Tree[nodeIdx];
	}

	if (start == end)
	{
		return Tree[nodeIdx] = value;
	}
	else
	{
		int mid = (start + end) / 2;

		pair<long long, int> leftNode = Update(start, mid, nodeIdx * 2, Idx, value);
		pair<long long, int> rightNode = Update(mid + 1, end, nodeIdx * 2 + 1, Idx, value);

		if (leftNode.first < rightNode.first)
		{
			return Tree[nodeIdx] = leftNode;
		}
		else if (leftNode.first > rightNode.first)
		{
			return Tree[nodeIdx] = rightNode;
		}
		else
		{
			if (leftNode.second < rightNode.second)
			{
				return Tree[nodeIdx] = leftNode;
			}
			else if (leftNode.second > rightNode.second)
			{
				return Tree[nodeIdx] = rightNode;
			}
		}
	}
}


int main()
{
	int N, M;

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
	}

	InitializeSegment(1, N, 1);

	cin >> M;

	for (int i = 1; i <= M; ++i)
	{
		int a, b;
		long long c;

		cin >> a >> b >> c;

		if (a == 1)
		{
			Update(1, N, 1, b, pair<long long, int>(c, b));
		}
		else
		{
			cout << Query(b, c, 1, 1, N).second << '\n';
		}

	}
	return 0;
}
