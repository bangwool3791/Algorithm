#include <string>
#include <vector>
#include <iostream>
using namespace std;

int emo = 0;
int price = 0;
vector<int> vec;
int arr[4] = { 10, 20, 30, 40 };

/*
* �̸�Ƽ�� ���� 7
* ���η��� ���� 4
* o(7^4 * 100) �뷫 160��
* dfs�� Ǭ��.
* 
*/
void dfs(vector<vector<int>> users, vector<int> emoticons)
{
    //���η��� �̸�Ƽ�� ������ŭ ����
    if (vec.size() == emoticons.size())
    {
        //���η� ���̽� ����
        //�̸�Ƽ�� �÷��� �������� �Ѽ�
        int emo_temp = 0;
        //������ ��
        int price_temp = 0;

        //��� �� ��ŭ �ݺ���
        for (int i = 0; i < users.size(); ++i)
        {
            //�� ����� ������ ��
            int p = 0;

            //�� ����� �ݺ���
            for (int j = 0; j < emoticons.size(); ++j)
            {
                //�ڽ��� ������ �̻��� ���� ��� �����Ѵ�.
                if (users[i][0] <= vec[j])
                {
                    //���� = ���� + �̸�Ƽ�� ���� * ���η�
                    p = p + emoticons[j] * (100 - vec[j]) / 100;
                }
            }
            //������ ������ �ִ� ���ݺ���, ���η��� ������ ������ ũ�ٸ� �̸�Ƽ�� �÷����� �����Ѵ�.
            if (users[i][1] <= p)
            {
                emo_temp++;
            }
            else
            {
                //������ ������ �ִ� ���ݺ��� ������ ������ �����Ѵ�.
                price_temp = price_temp + p;
            }
        }

        //��� * �̸�Ƽ�� ���Ű� ������
        //�̸�Ƽ�� �÷��� �����ڰ� ��� ���� �� ũ�ٸ�
        if (emo < emo_temp)
        {
            //������Ʈ
            emo = emo_temp;
            //���� ������Ʈ (���� ������)
            price = price_temp;
        }
        else if (emo == emo_temp && price < price_temp)
        {
            //�̸�Ƽ�� �Ǹž��� �ִ��� �ø��� ��.
            price = price_temp;
        }
        return;
    }

    //dfs
    for (int i = 0; i < 4; ++i)
    {
        vec.push_back(arr[i]);
        dfs(users, emoticons);
        vec.pop_back();
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    dfs(users, emoticons);
    answer.push_back(emo);
    answer.push_back(price);
    return answer;
}