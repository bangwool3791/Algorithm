#include <string>
#include <vector>
#include <iostream>
using namespace std;

int emo = 0;
int price = 0;
vector<int> vec;
int arr[4] = { 10, 20, 30, 40 };

/*
* 이모티콘 개수 7
* 할인률의 종류 4
* o(7^4 * 100) 대략 160만
* dfs로 푼다.
* 
*/
void dfs(vector<vector<int>> users, vector<int> emoticons)
{
    //할인률이 이모티콘 개수만큼 차면
    if (vec.size() == emoticons.size())
    {
        //할인률 케이스 마다
        //이모티콘 플러스 가입자의 총수
        int emo_temp = 0;
        //가격의 합
        int price_temp = 0;

        //사람 수 만큼 반복문
        for (int i = 0; i < users.size(); ++i)
        {
            //한 사람당 가격의 수
            int p = 0;

            //한 사람당 반복문
            for (int j = 0; j < emoticons.size(); ++j)
            {
                //자신의 할인율 이상인 것을 모두 구매한다.
                if (users[i][0] <= vec[j])
                {
                    //가격 = 가격 + 이모티콘 가격 * 할인률
                    p = p + emoticons[j] * (100 - vec[j]) / 100;
                }
            }
            //개인이 가지고 있는 가격보다, 할인률을 적용한 가격이 크다면 이모티콘 플러스를 구매한다.
            if (users[i][1] <= p)
            {
                emo_temp++;
            }
            else
            {
                //개인이 가지고 있는 가격보다 작으면 돈으로 구매한다.
                price_temp = price_temp + p;
            }
        }

        //사람 * 이모티콘 구매가 끝나면
        //이모티콘 플러스 가입자가 계산 값이 더 크다면
        if (emo < emo_temp)
        {
            //업데이트
            emo = emo_temp;
            //가격 업데이트 (낮은 값으로)
            price = price_temp;
        }
        else if (emo == emo_temp && price < price_temp)
        {
            //이모티콘 판매액을 최대한 늘리는 것.
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