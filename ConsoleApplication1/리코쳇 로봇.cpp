#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100
#define INF 987654321

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(int x, int y, int xSize, int ySize, vector<string>& board)
{
    vector<vector<int>> visited = vector(ySize, vector<int>(xSize));
    vector<vector<int>> depth = vector(ySize, vector<int>(xSize, INF));

    queue<pair<int, int>> q;

    q.push({ y, x });

    visited[y][x] = 1;
    depth[y][x] = 0;

    while (!q.empty())
    {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int _y = curRow;
            int _x = curCol;

            while (1)
            {
                _y += dy[i];
                _x += dx[i];

                if (_y < 0 || _y >= ySize || _x < 0 || _x >= xSize)
                {
                    _y -= dy[i];
                    _x -= dx[i];
                    break;
                }
                else if (board[_y][_x] == 'D')
                {
                    _y -= dy[i];
                    _x -= dx[i];
                    break;
                }
            }

            if (visited[_y][_x] == 1)
                continue;

            visited[_y][_x] = 1;
            depth[_y][_x] = min(depth[_y][_x], depth[curRow][curCol] + 1);
            q.push({ _y, _x });
        }

    }

    for (int i = 0; i < ySize; ++i)
    {
        for (int j = 0; j < xSize; ++j)
        {
            if (board[i][j] == 'G')
            {
                if (depth[i][j] == INF)return -1;
                else return depth[i][j];
            }
        }
    }
}

int solution(vector<string> board)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] == 'R')
            {
                return bfs(j, i, board[i].size(), board.size(), board);
            }
        }
    }
}