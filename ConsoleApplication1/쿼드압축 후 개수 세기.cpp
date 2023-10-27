#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> board;
int one;
int zero;

bool IsZero(int data, int left, int right, int top, int bottom)
{
    for (int i = top; i <= bottom; ++i)
    {
        for (int j = left; j <= right; ++j)
        {
            if (data != board[i][j])
                return false;
        }
    }

    return true;
}

void checkNum(int left, int right, int top, int bottom)
{
    for (int i = top; i <= bottom; ++i)
    {
        for (int j = left; j <= right; ++j)
        {
            if (board[i][j])
                one++;
            else
                zero++;
        }
    }
}

void dfs(int left, int right, int top, int bottom)
{
    if (IsZero(board[top][left], left, right, top, bottom))
    {
        if (board[top][left])
            one++;
        else
            zero++;

        return;
    }

    if (right - left == 1)
    {
        checkNum(left, right, top, bottom);
        return;
    }

    IsZero(board[top][left], left, right, top, bottom);

    int rowmid = (right + left) / 2;
    int colmid = (bottom + top) / 2;
    dfs(left, rowmid, top, colmid);
    dfs(rowmid + 1, right, top, colmid);
    dfs(left, rowmid, colmid + 1, bottom);
    dfs(rowmid + 1, right, colmid + 1, bottom);

}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    board = arr;
    int row = arr[0].size();
    int col = arr.size();
    dfs(0, row - 1, 0, col - 1);
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}