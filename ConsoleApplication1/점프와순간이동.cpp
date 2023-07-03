#include <iostream>
#include <cmath>

using namespace std;


/*
* 100을 넘어갈 경우 1 -> 2 -> 4 -> ... -> 50 -> 100
* 절반으로 가면 가장 빠름
* 150의 경우 150 -> 75 -> 37.5 -> 18 -> 9 -> 4.5 -> 2 -> 1 이다. 37.5로 가는 방법은 jump를 한번 더 뛰는 방법이다.
* 홀수의 경우 짝수 + 1인 것을 알 수 있음
* * 74 -> 37 -> 18 -> 9
*/
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