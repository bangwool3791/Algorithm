#include "pch.h"

int N, K;
int Count{};
int i{}, j{}, k{};

vector<int> originCnt{};

int Sum(vector<int>& vec, int index, vector<int>& cnt)
{
	static int i{};
	i = index;
	

}

int main()
{

	cin >> N;
	cin >> K;
	vector<int> vec(N);
	vector<int> cnt(N);
	for (int i{ 0 }; i < N; ++i)
	{
		int value{};
		cin >> value;
		vec[i] = value;
	}


	for (int i{ 0 }; i < N; ++i)
	{
		cnt[i] = K / vec[i];
		originCnt.push_back(cnt[i]);
	}

	for (int i{ N -1}; i >= 0; ++i)
	{
		int a = Sum(vec, i, cnt);

		if (a == K)
		{
			Count++;
		}
	}

	cout << Count;

	return 0;
}
