#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int foodSize = 0;

    unordered_map<string, int> food;
    unordered_map<string, int> foodCopy;

    for (int i = 0; i < want.size(); ++i)
    {
        food[want[i]] = number[i];
        foodSize += number[i];
    }

    for (int i = 9; i < discount.size(); ++i)
    {
        int temp = foodSize;
        foodCopy = food;

        for (int j = i - 9; j <= i; ++j)
        {
            if (foodCopy[discount[j]] != 0)
            {
                temp--;
                foodCopy[discount[j]] -= 1;
            }
        }

        if (temp == 0)
            answer++;
    }
    return answer;
}