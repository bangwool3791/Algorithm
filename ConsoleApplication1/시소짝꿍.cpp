#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 1001

long long solution(vector<int> weights) {
    long long answer = 0;

    /*
    �ߺ� �� ���� ���԰� ���� Ȯ�� nC2
    n * (n - 1) /2;
    ���԰� ���� dp�� ����Ѵ�.
    ���԰� ���� ����� ����
    1:1, 1:2, 2:3, 3:4 �̴�.
    1:1�� ��� nC2�� Ǯ��,
    ������ ����� ���� ���� ���Ѵ�.
    ���԰� 1,2,3�� ��� �� ��, ��ʽ����� x�� ���Ѵ�.
    x�� ������ �ִ밪�� ���� �ʴ��� Ȯ���Ѵ�.
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