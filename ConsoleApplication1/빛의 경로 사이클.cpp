#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
/*
(0)왼쪽 (1)오른쪽 (2)아래 (3)위
*/
vector<string> MAP;
int dirX[4] = { 0, 0, 1, -1 };
int dirY[4] = { 1, -1, 0, 0 };
bool Visit[510][510][4];
int N = 0;
int M = 0;

int Change_Dir(char C, int Dir)
{
    if (C == 'L')
    {
        if (Dir == 0) return 3;
        if (Dir == 1) return 2;
        if (Dir == 2) return 0;
        if (Dir == 3) return 1;
    }
    else if (C == 'R')
    {
        if (Dir == 0) return 2;
        if (Dir == 1) return 3;
        if (Dir == 2) return 1;
        if (Dir == 3) return 0;
    }
    return Dir;
}


int Simulation(int x, int y, int Dir, int Len)
{
    if (Visit[y][x][Dir] == true)
        return Len;

    Visit[y][x][Dir] = true;

    int nx = x;
    int ny = y;
    int nd = Dir;

    nd = Change_Dir(MAP[y][x], Dir);

    nx = x + dirX[nd];
    ny = y + dirY[nd];

    if (nx < 0) nx = M - 1;
    if (ny < 0) ny = N - 1;
    if (nx >= M) nx = 0;
    if (ny >= N) ny = 0;

    return Simulation(nx, ny, nd, Len + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    N = grid.size();
    M = grid[0].length();
    MAP = grid;

    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                int Result = Simulation(j, i, k, 0);

                if (Result)
                    answer.push_back(Result);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}