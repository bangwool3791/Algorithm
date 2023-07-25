#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int swap(vector<vector<int>>& board, pair<int, int> up, pair<int, int> down)
{
    int result = 987654321;

    vector<vector<int>> copy = board;

    int col1 = up.first - 1;
    int col2 = down.first - 1;

    int row1 = up.second - 1;
    int row2 = down.second - 1;

    int idx = row1;

    while (idx < row2)
    {
        board[col1][idx + 1] = copy[col1][idx];
        result = min(copy[col1][idx], result);
        ++idx;
    }

    idx = col1;

    while (idx < col2)
    {
        board[idx + 1][row2] = copy[idx][row2];
        result = min(copy[idx][row2], result);
        ++idx;
    }

    idx = row2;

    while (row1 < idx)
    {
        board[col2][idx - 1] = copy[col2][idx];
        result = min(copy[col2][idx], result);
        --idx;
    }

    idx = col2;

    while (col1 < idx)
    {
        board[idx - 1][row1] = copy[idx][row1];
        result = min(copy[idx][row1], result);
        --idx;
    }

    return result;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int>(columns));

    int num = 1;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
            board[i][j] = num++;
    }

    for (int i = 0; i < queries.size(); ++i)
    {
        int result = swap(board, { queries[i][0], queries[i][1] }, { queries[i][2], queries[i][3] });
        answer.push_back(result);
    }
    return answer;
}