#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 100
#define INF 987654321

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1,  0, -1 };

int bfs(int x, int y, int destx, int desty, const vector<string>& maps, int n, int m)
{
    vector<vector<int>> dp = vector(MAX, vector(MAX, 0));
    vector<vector<int>> depth = vector(MAX, vector(MAX, INF));
    queue<pair<int, int>> que;

    que.push({ x,y });
    depth[y][x] = 0;

    int cnt = 0;
    while (!que.empty())
    {
        int nx = que.front().first;
        int ny = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nextCol = nx + dx[i];
            int nextRow = ny + dy[i];

            if (nextCol < 0 || nextCol >= n || nextRow < 0 || nextRow >= m)
                continue;

            if (dp[nextRow][nextCol] == 1)
                continue;

            if (maps[nextRow][nextCol] == 'X')
                continue;

            dp[nextRow][nextCol] = 1;

            depth[nextRow][nextCol] = min(depth[nextRow][nextCol], depth[ny][nx] + 1);

            que.push({ nextCol, nextRow });
        }
    }
    return depth[desty][destx];
}
int solution(vector<string> maps) {

    int answer = 0;

    int startX = 0, startY = 0;
    int lX = 0, lY = 0;
    int eX = 0, eY = 0;
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {

            if (maps[i][j] == 'S')
            {
                startX = j;
                startY = i;
            }
            else if (maps[i][j] == 'L')
            {
                lX = j;
                lY = i;
            }
            else if (maps[i][j] == 'E')
            {
                eX = j;
                eY = i;
            }
        }
    }

    int startToLaber = bfs(startX, startY, lX, lY, maps, maps[startY].size(), maps.size());
    int LaberToDest = bfs(lX, lY, eX, eY, maps, maps[lY].size(), maps.size());

    if (INF <= startToLaber || INF <= LaberToDest)
        return -1;

    return startToLaber + LaberToDest;
}