#include <iostream>
#include <cmath>

using namespace std;


/*
* 100�� �Ѿ ��� 1 -> 2 -> 4 -> ... -> 50 -> 100
* �������� ���� ���� ����
* 150�� ��� 150 -> 75 -> 37.5 -> 18 -> 9 -> 4.5 -> 2 -> 1 �̴�. 37.5�� ���� ����� jump�� �ѹ� �� �ٴ� ����̴�.
* Ȧ���� ��� ¦�� + 1�� ���� �� �� ����
* * 74 -> 37 -> 18 -> 9
*/
int solution(int n)
{
    int ans = 1;
    int cur = 1;

    while (1 < n)
    {
        //cout << n << endl;
        if (n % 2 == 1)
        {
            ans++;
        }
        n /= 2;
    }

    return ans;
}