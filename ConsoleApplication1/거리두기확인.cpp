#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool bfs(int x, int y, vector<string> places)
{
    vector<vector<bool>> dp(5, vector<bool>(5, false));
    queue<pair<int, pair<int, int>>> que;
    que.push({ 0,{x, y} });

    dp[y][x] = true;

    while (!que.empty())
    {
        int cnt = que.front().first;
        int x = que.front().second.first;
        int y = que.front().second.second;
        que.pop();

        if (cnt == 2)
            continue;

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            {
                if (!dp[ny][nx])
                {
                    if (places[ny][nx] == 'O')
                    {
                        dp[ny][nx] = true;
                        que.push({ cnt + 1,{nx, ny} });
                    }
                    else if (places[ny][nx] == 'P')
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool find_answer(vector<string> MAP)
{
    for (int j = 0; j < MAP.size(); ++j)
    {
        for (int k = 0; k < MAP[j].size(); ++k)
        {
            if (MAP[j][k] == 'P')
            {
                if (!bfs(k, j, MAP))
                {
                    return false;
                }
            }
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); ++i)
    {
        answer.push_back(find_answer(places[i]));
    }
    return answer;
}