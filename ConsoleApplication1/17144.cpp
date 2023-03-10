#include "pch.h"

int r, c, t;

// room -> �̼����� ������ ��
int room[51][51];
// room�� �Ѽ� ���� ���� ������ ���� ��
int add[51][51];
// bfs ��� ���� �迭
int dr[4] = { 0,  1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };

//���� û���� ����, �Ʒ���
int up_row, down_row;
//���� �ѷ�
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
                //ó�� �Է� �Ǵ� ���� û����� �� ���̴�.
                if(!flag)
                { 
                    up_row = i;
                    //�÷��׸� true�� �����.
                    flag = true;
                }
                else
                {
                    //���� û���� ���� ���� �Է� �޴´�.
                    down_row = i;
                }
            }
            else
            {
                //���� �ѷ��� ������Ų��.
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
            //�̼����� �л귮�� ���ϰ�
            int val = room[i][j] / 5;

            //���� ����ְų�, ���� û�����̸� �����Ѵ�.
            if (0 == room[i][j] || room[i][j] == -1)
                continue;

            //4���� Ž���� ����
            for (int k = 0; k < 4; ++k)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                //�ʿ��� ����� ����
                if (nr < 0 || nr >= r || nc < 0 || nc >= c)
                    continue;
                //���� û���� �̸� ����
                if(room[nr][nc] == -1)
                    continue;

                //�̼� ���� Ȯ�귮�� ���� ���Ѵ�.
                add[nr][nc] += val;
                //Ȯ�� �̼� �������� ���Ѵ�.
                cnt++;
            }
            //ī��Ʈ ��ŭ add���� �A��.
            add[i][j] -= (cnt * val);
        }
    }

    // �̼����� Ȯ�� ������Ʈ
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
    /*
    * �̼����� �ѷ����� 
    * ���� û���� �Ӹ� ��, �� �Ʒ� �������� ����.
    */
    total_dust -= room[up_row - 1][0];
    total_dust -= room[down_row + 1][0];

    /*
    * ���� ���� ��ȯ (�ݽð�)
    * 1. ������
    */
    for (int i = up_row - 1; i > 0; i--)
        room[i][0] = room[i - 1][0];
    //2. ����
    for (int i = 0; i < c - 1; i++)
        room[0][i] = room[0][i + 1];
    //3. ��������
    for (int i = 1; i <= up_row; i++)
        room[i - 1][c - 1] = room[i][c - 1];
    //4. �Ʒ���
    for (int i = c - 1; i > 1; i--)
        room[up_row][i] = room[up_row][i - 1];

    room[up_row][1] = 0;
    //1. ������
    for (int i = down_row + 1; i < r - 1; ++i)
        room[i][0] = room[i + 1][0];

    //2. �Ʒ���
    for (int i = 0; i < c - 1; ++i)
        room[r - 1][i] = room[r - 1][i + 1];

    //3. ��������
    for (int i = r - 1; i > down_row; --i)
        room[i][c - 1] = room[i - 1][c - 1];

    //4. ����
    for (int i = c - 1; i > 0; --i)
        room[down_row][i] = room[down_row][i - 1];

    room[down_row][1] = 0;

}

void solve()
{
    while (t--)
    {
        // �̼����� Ȯ��
        spreadDust();
        // �����ȯ�� ���� �̼����� �̵�
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