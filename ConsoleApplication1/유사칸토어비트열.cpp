#include "pch.h"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int answer = 0;

void recur(int n, long long l, long long r)
{
    long long range = 1LL * pow(5, n - 1);//n번째 유사 칸토어 비트열길이를 5구간으로 나눈 길이
    int s = l / range, e = r / range;// 몇번째 구간에 존재하는지
    if (n == 1)
    {
        for (int i = l; i <= r; i++) if (i != 2) answer++;// n==1 일때 칸토어 비트열은 11011이므로
        return;
    }
    for (int i = s + 1; i < e; i++) if (i != 2) answer += (int)pow(4, n - 1);// 시작 구간과 종료구간 사이의 값++
    if (s == e) recur(n - 1, l - range * s, r - range * e);// 시작 종료 구간이 동일하다면
    else
    {
        if (s != 2) recur(n - 1, l - range * s, range - 1);//3번째 구간이 아니라면 시작구간 에서 range - 1까지
        if (e != 2) recur(n - 1, 0, r - range * e);//3번째 구간이 아니라면 0에서 종료구간까지
    }
}

int solution(int n, long long l, long long r)
{
    recur(n, --l, --r);
    return answer;
}

int main()
{
    int n, l, r;

    cin >> n >> l >> r;
    solution(n, l, r);
    return 0;
}