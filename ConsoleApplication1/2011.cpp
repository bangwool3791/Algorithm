#include "pch.h"

#define MAX 5000
#define Moduler 1000000
int Arr[MAX]; 
int DP[MAX], Len; 
string Inp;

int main()
{
	cin >> Inp;
	int L = Inp.size();

	DP[0] = 1;

	for (int i{ 1 }; i <= L; ++i)
	{
		Arr[i] = Inp[i-1] - '0';
	}

	DP[0] = 1;
	for (int i{ 1 }; i <= L; ++i)
	{
		if (1 <= Arr[i] && Arr[i] <= 9)
		{
			DP[i] = (DP[i - 1] + DP[i]) % Moduler;
		}
		if (i == 1)
			continue;

		int temp = Arr[i - 1] * 10 + Arr[i];
		if (10 <= temp && temp <= 26)
		{
			DP[i] = (temp) % Moduler;
		}
	}

	cout << DP[L];
	return 0;
}