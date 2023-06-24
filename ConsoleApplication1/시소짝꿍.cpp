#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 1001

long long solution(vector<int> weights) {
    long long answer = 0;

    /*
    중복 된 같은 무게가 나올 확률 nC2
    n * (n - 1) /2;
    무게가 나올 dp를 계산한다.
    무게가 같을 경우의 수는
    1:1, 1:2, 2:3, 3:4 이다.
    1:1일 경우 nC2로 풀고,
    나머지 경우의 수는 각각 구한다.
    무게가 1,2,3의 배수 일 때, 비례식으로 x를 구한다.
    x가 무게의 최대값을 넘지 않는지 확인한다.
    */
    vector<long long> dp(MAX, 0);
    vector<int> vis(MAX, 0);

    for (auto i : weights)
        dp[i] += 1;

    for (auto i : weights)
    {
        if (dp[i] > 1 && !vis[i])
        {
            answer += (dp[i] * (dp[i] - 1)) / 2;
            vis[i] = 1;
        }

        if (i * 2 < MAX && dp[i * 2])
        {
            answer += dp[i * 2];
        }

        if (i % 3 == 0 && i / 3 * 4 < MAX && dp[i / 3 * 4])
        {
            answer += dp[i / 3 * 4];
        }

        if (i % 2 == 0 && i / 2 * 3 < MAX && dp[i / 2 * 3])
        {
            answer += dp[i / 2 * 3];
        }
    }
    return answer;
}