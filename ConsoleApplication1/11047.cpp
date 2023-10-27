#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, n;

    cin >> k >> n;

    vector<int> coins;
    for (int i = 0; i < k; ++i)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    int idx = coins.size() - 1;
    int sum = 0;
    int answer = 0;
    while (idx >= 0)
    {
        sum += coins[idx];
        ++answer;
        if (sum > k)
        {
            --answer;
            sum -= coins[idx];
            --idx;
        }
        else if (sum == k)
            break;
    }
    cout << answer << endl;
}