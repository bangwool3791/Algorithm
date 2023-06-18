#include <string>
#include <vector>

using namespace std;

int isWin(int x, int y, vector<pair<int, int>> dir, vector<string> board)
{
    int result = 0;

    for (int i = 0; i < 8; ++i)
    {
        int j = 0;

        for (j = 1; j <= 2; ++j)
        {
            int nx = x + dir[i].first * j;
            int ny = y + dir[i].second * j;

            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                break;
            if (board[ny][nx] != board[y][x]) break;
        }

        if (j == 3) result += 1;
    }

    return result;
}

int solution(vector<string> board) {
    int answer = -1;

    vector<pair<int, int>> dir;

    dir.push_back({ 1, 0 });
    dir.push_back({ 1, 1 });
    dir.push_back({ 0, 1 });
    dir.push_back({ -1, 1 });
    dir.push_back({ -1, 0 });
    dir.push_back({ -1, -1 });
    dir.push_back({ 0, -1 });
    dir.push_back({ 1, -1 });

    int allocO = 0;
    int allocX = 0;
    int winO = 0;
    int winX = 0;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 'O')
                ++allocO;
            else if (board[i][j] == 'X')
                ++allocX;
        }
    }

    if (allocO - allocX > 1 || allocX > allocO) return 0;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 'O')
            {
                winO += isWin(j, i, dir, board);

                if (winO && winX) return 0;
            }
            else if (board[i][j] == 'X')
            {
                winX += isWin(j, i, dir, board);

                if (winO && winX) return 0;
            }
        }
    }

    if (
        (winO / 2 == 1 && allocO - allocX == 1)
        ||
        (winX / 2 == 1 && allocO - allocX == 0)
        ||
        (winO / 2 == 0 && winX / 2 == 0)
        ||
        (winO / 2 == 2 && allocO == 5)
        ) return 1;
    else return 0;

    return answer;
}