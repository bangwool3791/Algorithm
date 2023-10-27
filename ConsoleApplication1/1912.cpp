#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<int> input = vector<int>(N);
	vector<int> DP = vector<int>(N);

	for (int i = 0; i < N; ++i)
		cin >> input[i];

	DP[0] = input[0] + input[1];
	DP[1] = max(max(DP[0] + input[1], DP[0]), input[1]);
	for (int i = 2; i < N; ++i)
	{
		DP[i] = max(max(DP[i - 1] + input[i], DP[i - 1]), input[i]);
	}
	
	return 0;
}