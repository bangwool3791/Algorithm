#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0, m = 0;
int answer = 0;
vector<vector<int>> valid;
vector<vector<int>> paper;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dx1[4] = { -1, 0, 0, 1 };
int dy1[4] = { 0, 0,-1, 0 };

int dx2[4] = { 0, 0, 0, 1 };
int dy2[4] = { 1, 0,-1, 0 };

int dx3[4] = { 0, 0, -1, 1 };
int dy3[4] = { 0, 1, 0, 0 };

int dx4[4] = { 0, -1, 0, 0 };
int dy4[4] = { 0, 0, 1, -1 };

void triangle(int x, int y, int* dx, int* dy)
{
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            return;

        sum += paper[ny][nx];
    }

    answer = max(answer, sum);
}

void dfs(int depth, int x, int y, int sum)
{
    if (depth == 3)
    {
        answer = max(answer, sum);
        return;
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            valid[ny][nx] = true;
            sum += paper[ny][nx];
            dfs(depth + 1, nx, ny, sum);
            valid[ny][nx] = false;
        }
    }
}

int main()
{
    cin >> n >> m;

    valid = vector<vector<int>>(n, vector<int>(m, 0));
    paper = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> paper[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            dfs(0, j, i, 0);
            triangle(j, i, dx1, dy1);
            triangle(j, i, dx2, dy2);
            triangle(j, i, dx3, dy3);
            triangle(j, i, dx4, dy4);
        }
    cout << answer << endl;
    return 0;
}