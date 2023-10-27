#include <iostream>
#include <vector>
using namespace std;
vector<int> DP;

int a = 0;
int b = 0;

int fibonacci1(int n)
{
    if (n == 1 || n == 2)
    {
        ++a;
        return 1;
    }
    else return fibonacci1(n - 1) + fibonacci1(n - 2);
}
int fibonacci2(int n)
{
    DP[0] = 1;
    DP[1] = 1;

    for (int i = 2; i < n; ++i)
    {
        ++b;
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    return DP[n];
}

int main()
{
    int N = 0;
    cin >> N;

    DP = vector<int>(N + 1);
    fibonacci1(N);
    fibonacci2(N);
    cout << a << b << endl;
    return 0;
}