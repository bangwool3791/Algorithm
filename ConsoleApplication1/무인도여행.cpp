#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int dirX[4] = { 1, -1, 0, 0 };
int dirY[4] = { 0, 0, 1, -1 };
int dp[100][100] = { 0, };

int bfs(int x, int y, int col, int row, vector<string> maps)
{
    queue<pair<int, int>> que;

    que.push({ x,y });
    dp[y][x] = true;

    int answer = maps[y][x] - '0';
    cout << answer << endl;
    while (!que.empty())
    {
        int curRow = que.front().second;
        int curCol = que.front().first;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = curCol + dirX[i];
            int ny = curRow + dirY[i];

            if (dp[ny][nx] == true)
                continue;

            if (ny < 0 || ny >= row || nx < 0 || nx >= col)
                continue;

            if (maps[ny][nx] == 'X')
                continue;

            dp[ny][nx] = true;
            answer += maps[ny][nx] - '0';
            que.push({ nx, ny });
        }
    }
    return answer;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;


    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].length(); ++j)
        {
            if (!dp[i][j] && maps[i][j] != 'X')
            {
                answer.push_back(bfs(j, i, maps[i].length(), maps.size(), maps));
            }
        }
    }

    if (answer.size() == 0)
    {
        answer.push_back(-1);
        return answer;
    }


    sort(answer.begin(), answer.end());
    return answer;
}
