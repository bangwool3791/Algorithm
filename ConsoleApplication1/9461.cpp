#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N = 0;
    int num = 0;
    cin >> N;
    vector<long long> DP = vector<long long>(101, 0);
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 1;

    for (int i = 3; i <= 100; ++i)
        DP[i] = DP[i - 2] + DP[i - 3];

    while (N--)
    {
        cin >> num;
        cout << DP[num - 1] << endl;
    }
    return 0;
}