#include "pch.h"

#define MAX 100'001

int n = 0;
int m = 0;
long long A[MAX];
long long Tree[MAX];
void Update(int idx, int k)
{
	for (int i = idx; i <= n; i += (i & -i))
	{
		Tree[i] += k;
	}
}

long long Sum(int idx)
{
	long long ret = 0;

	for (int i = idx; i > 0; i -= (i & -i))
	{
		ret += Tree[i];
	}

	return ret;
}

int main()
{
	cin >> n;

	cin >> A[1];
	Update(1, A[1]);

	int data = A[1];

	for (int i = 2; i <= n; ++i)
	{
		cin >> A[i];
		Update(i, A[i] - data);
		data = A[i];
	}

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c = 0;
		long long d = 0;

		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			Update(b, d);
			Update(c + 1, -d);
		}
		else
		{
			cin >> b;
			cout << Sum(b) << '\n';
		}
	}
	return 0;
}