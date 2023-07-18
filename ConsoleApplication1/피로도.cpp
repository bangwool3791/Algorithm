#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int dp[8];
int answer = 0;

void dfs(vector<vector<int>> dungeons, int index, int k, int depth)
{
    if (k >= dungeons[index][0])
    {
        k -= dungeons[index][1];
        answer = max(answer, depth);
    }
    else
    {
        return;
    }
    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (dp[i] == 0)
        {
            dp[i] = 1;
            dfs(dungeons, i, k, depth + 1);
            dp[i] = 0;
        }

    }
}
int solution(int k, vector<vector<int>> dungeons) {
    for (int i = 0; i < dungeons.size(); ++i)
    {
        dp[i] = 1;
        dfs(dungeons, i, k, 1);
        dp[i] = 0;
    }

    return answer;
}