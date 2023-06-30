#include <iostream>
#include <cmath>

using namespace std;

int solution(int n)
{
    int ans = 1;
    int cur = 1;

    while (1 < n)
    {
        //cout << n << endl;
        if (n % 2 == 1)
        {
            ans++;
        }
        n /= 2;
    }

    return ans;
}