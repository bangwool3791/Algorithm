#include "pch.h"
#define MAX 100'001

long long X[MAX];
long long Tree[MAX * 4];

long long InitSegment(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		return Tree[nodeIdx] = X[left];
	}

	int mid = (left + right) / 2;

	return Tree[nodeIdx] = InitSegment(left, mid, nodeIdx * 2) * InitSegment(mid + 1, right, nodeIdx * 2 + 1);
}

long long Update(int left, int right, int nodeIdx, int Idx, long long value)
{
	if (left > Idx || right < Idx)
	{
		return Tree[nodeIdx];
	}

	if (left != right)
	{
		int mid = (left + right) / 2;

		return Tree[nodeIdx] = Update(left, mid, nodeIdx * 2, Idx, value) * Update(mid + 1, right, nodeIdx * 2 + 1, Idx, value);
	}
	else
	{
		return Tree[nodeIdx] = value;
	}
}

long long Query(int left, int right, int nodeIdx, int start, int end)
{
	if (left > end || right < start)
	{
		return 1;
	}

	if (start <= left && right <= end)
	{
		return Tree[nodeIdx];
	}

	int mid = (left + right) / 2;

	return Query(left, mid, nodeIdx * 2, start, end) * Query(mid + 1, right, nodeIdx * 2 + 1, start, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;

	while (cin >> N >> K)
	{
		for (int i = 1; i <= N; ++i)
		{
			int a = 0;

			cin >> a;

			if (a > 0)
				X[i] = 1;
			else if (a < 0)
				X[i] = -1;
			else
				X[i] = 0;
		}

		InitSegment(1, N, 1);

		for (int i = 1; i <= K; ++i)
		{
			char a; int b, c;

			cin >> a >> b >> c;

			if (a == 'C')
			{
				if (c > 0)
					c = 1;
				else if (c < 0)
					c = -1;
				else
					c = 0;

				Update(1, N, 1, b, c);
			}
			else
			{
				long long answer = Query(1, N, 1, b, c);

				if (answer > 0)
					cout << '+';
				else if (answer < 0)
					cout << '-';
				else 
					cout << '0';
			}
		}

		cout << '\n';
	}

	return 0;
}