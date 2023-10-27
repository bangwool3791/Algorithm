#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 0, K = 0, L = 0;
int dir = 0;
int answerTime = -1;
vector<vector<int>> board;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue<pair<int, string>> snake_dir;
queue<pair<int, int>> tail_pos;
void print()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << " ";

        cout << endl;
    }
    cout << answerTime << endl;
}
void GetRightDir()
{
    if (dir == 0)
        dir = 3;
    else if (dir == 1)
        dir = 0;
    else if (dir == 2)
        dir = 1;
    else if (dir == 3)
        dir = 2;
}

void GetLeftDir()
{
    if (dir == 0)
        dir = 1;
    else if (dir == 1)
        dir = 2;
    else if (dir == 2)
        dir = 3;
    else if (dir == 3)
        dir = 0;
}

void Progress()
{
    queue<pair<int, int>> PosQueue;
    PosQueue.push({ 0,0 });

    while (!PosQueue.empty())
    {
        ++answerTime;

        if (!snake_dir.empty() && snake_dir.front().first == answerTime)
        {
            string dirString = snake_dir.front().second;
            if (dirString == "L")
            {
                GetLeftDir();
            }
            else if (dirString == "D")
            {
                GetRightDir();
            }
            snake_dir.pop();
        }

        pair<int, int> pos = PosQueue.front();
        PosQueue.pop();
        tail_pos.push({ pos });

        pair<int, int> newPos{ pos.first + dy[dir], pos.second + dx[dir] };

        if (newPos.first < 0 || newPos.first >= N || newPos.second < 0 || newPos.second >= N)
        {
            ++answerTime;
            return;
        }

        if (board[newPos.first][newPos.second] == 1)
        {
            ++answerTime;
            return;
        }

        if (board[newPos.first][newPos.second] == 2)
        {
            board[newPos.first][newPos.second] = 1;
        }
        else if (board[newPos.first][newPos.second] == 0)
        {
            if (!tail_pos.empty())
            {
                board[tail_pos.front().first][tail_pos.front().second] = 0;
                tail_pos.pop();
            }
            board[newPos.first][newPos.second] = 1;
        }
        PosQueue.push(newPos);
    }
}

int main()
{
    cin >> N >> K;
    board = vector<vector<int>>(N, vector<int>(N, 0));
    board[0][0] = 1;

    for (int i = 0; i < K; ++i)
    {
        int x = 0; int y = 0;
        cin >> y >> x;
        board[y - 1][x - 1] = 2;
    }
    cin >> L;

    for (int i = 0; i < L; ++i)
    {
        int time = 0;
        string direction = "";
        cin >> time >> direction;
        snake_dir.push({ time, direction });
    }
    Progress();
    cout << answerTime << endl;
    return 0;
}