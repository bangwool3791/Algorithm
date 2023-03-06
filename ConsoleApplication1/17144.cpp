#include "pch.h"

int r, c, t;
int room[51][51];
int add[51][51];
int dr[4] = { 0,  1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };

int up_row, down_row;
int total_dust;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;

    bool flag = false;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> room[i][j];

            if (-1 == room[i][j])
            {
                if(!flag)
                { 
                    up_row = i;
                    flag = true;
                }
                else
                {
                    down_row = i;
                }
            }
            else
            {
                total_dust += room[i][j];
            }
        }
    }
}

void spreadDust()
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            int cnt = 0;
            int val = room[i][j] / 5;

            if (0 == room[i][j] || room[i][j] == -1)
                continue;

            for (int k = 0; k < 4; ++k)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr < 0 || nr >= r || nc < 0 || nc >= c)
                    continue;

                if(room[nr][nc] == -1)
                    continue;

                add[nr][nc] += val;
                cnt++;
            }
            add[i][j] -= (cnt * val);
        }
    }

    // 미세먼지 확산 업데이트
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            room[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}

void airCleaner()
{
    total_dust -= room[up_row - 1][0];
    total_dust -= room[down_row + 1][0];

    /*
    * 위의 공기 순환 (반시계)
    * 1. 왼쪽줄
    */
    for (int i = up_row - 1; i > 0; i--)
        room[i][0] = room[i - 1][0];
    //2. 윗줄
    for (int i = 0; i < c - 1; i++)
        room[0][i] = room[0][i + 1];
    //3. 오른쪽줄
    for (int i = 1; i <= up_row; i++)
        room[i - 1][c - 1] = room[i][c - 1];
    //4. 아랫줄
    for (int i = c - 1; i > 1; i--)
        room[up_row][i] = room[up_row][i - 1];

    room[up_row][1] = 0;
    //1. 왼쪽줄
    for (int i = down_row + 1; i < r - 1; ++i)
        room[i][0] = room[i + 1][0];

    //2. 아랫줄
    for (int i = 0; i < c - 1; ++i)
        room[r - 1][i] = room[r - 1][i + 1];

    //3. 오른쪽줄
    for (int i = r - 1; i > down_row; --i)
        room[i][c - 1] = room[i - 1][c - 1];

    //4. 윗줄
    for (int i = c - 1; i > 0; --i)
        room[down_row][i] = room[down_row][i - 1];

    room[down_row][1] = 0;

}

void solve()
{
    while (t--)
    {
        // 미세먼지 확산
        spreadDust();
        // 공기순환에 의한 미세먼지 이동
        airCleaner();
    }
    cout << total_dust << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}