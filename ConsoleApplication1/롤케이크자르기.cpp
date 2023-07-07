#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    vector<int> leftDP = vector<int>(10'001, 0);
    vector<int> rightDP = vector<int>(10'001, 0);

    int rightTopping = 0;
    int leftTopping = 0;

    for (int i = 0; i < topping.size(); ++i)
    {
        if (rightDP[topping[i]] == 0)
        {
            rightTopping += 1;
        }
        rightDP[topping[i]] += 1;
    }

    for (int i = 0; i < topping.size(); ++i)
    {
        if (leftDP[topping[i]] == 0)
        {
            leftDP[topping[i]] = 1;
            ++leftTopping;
        }

        if (0 < rightDP[topping[i]])
        {
            rightDP[topping[i]] -= 1;

            if (rightDP[topping[i]] == 0)
            {
                rightTopping -= 1;
            }
        }

        if (leftTopping == rightTopping)
        {
            ++answer;
        }
    }
    return answer;
}