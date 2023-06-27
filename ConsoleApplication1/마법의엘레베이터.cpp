#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey)
{
    int answer = 0;

    while (0 < storey)
    {
        int n = storey % 10;

        if (n >= 6)
        {
            answer += 10 - n;
            storey /= 10;
            storey += 1;
        }
        else if (n == 5)
        {
            int temp = (storey / 10) % 10;

            if (temp >= 5)
            {
                answer += 10 - n;
                storey /= 10;
                storey += 1;
            }
            else
            {
                answer += n;
                storey /= 10;
            }
        }
        else
        {
            answer += n;
            storey /= 10;
        }
    }

    return answer;
}