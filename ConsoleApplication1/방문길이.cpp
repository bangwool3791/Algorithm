#include <string>
#include <iostream>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int answer = 0;

void dfs(string dirs, int x, int y)
{
    bool dp[11][11][11][11];

    for (int i = 0; i < 11; ++i)
        for (int j = 0; j < 11; ++j)
            for (int k = 0; k < 11; ++k)
                for (int m = 0; m < 11; ++m)
                    dp[i][j][k][m] = false;

    for (int i = 0; i < dirs.size(); ++i)
    {
        int dir = 0;
        //cout << dirs[i]  << endl;
        if (dirs[i] == 'L')
            dir = 0;
        else if (dirs[i] == 'R')
            dir = 1;
        else if (dirs[i] == 'D')
            dir = 2;
        else if (dirs[i] == 'U')
            dir = 3;

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        //cout << nx << " " << ny << " " << dp[ny][nx][dir] << endl;
        if (0 > nx || 10 < nx || 0 > ny || 10 < ny)
            continue;

        if (dp[ny][nx][y][x] == false)
        {
            ++answer;

            dp[ny][nx][y][x] = true;
            dp[y][x][ny][nx] = true;
        }
        x = nx;
        y = ny;
    }
}

int solution(string dirs) {
    dfs(dirs, 5, 5);
    return answer;
}