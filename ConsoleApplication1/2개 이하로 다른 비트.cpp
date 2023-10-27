#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (const auto& number : numbers)
    {
        if (number % 2 == 0)
        {
            answer.push_back(number + 1);
        }
        else
        {
            long long temp = number - 1;
            long long num2 = 1;
            while (temp <= number)
            {
                temp = number ^ num2;

                if (temp < number)
                {
                    num2 *= 2;

                }
                else
                {
                    temp ^= num2 / 2;
                }
            }
            answer.push_back(temp);
        }
    }

    return answer;
}