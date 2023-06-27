#include "pch.h"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int answer = 0;

void recur(int n, long long l, long long r)
{
    long long range = 1LL * pow(5, n - 1);//n��° ���� ĭ��� ��Ʈ�����̸� 5�������� ���� ����
    int s = l / range, e = r / range;// ���° ������ �����ϴ���
    if (n == 1)
    {
        for (int i = l; i <= r; i++) if (i != 2) answer++;// n==1 �϶� ĭ��� ��Ʈ���� 11011�̹Ƿ�
        return;
    }
    for (int i = s + 1; i < e; i++) if (i != 2) answer += (int)pow(4, n - 1);// ���� ������ ���ᱸ�� ������ ��++
    if (s == e) recur(n - 1, l - range * s, r - range * e);// ���� ���� ������ �����ϴٸ�
    else
    {
        if (s != 2) recur(n - 1, l - range * s, range - 1);//3��° ������ �ƴ϶�� ���۱��� ���� range - 1����
        if (e != 2) recur(n - 1, 0, r - range * e);//3��° ������ �ƴ϶�� 0���� ���ᱸ������
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