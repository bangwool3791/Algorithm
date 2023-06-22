#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    answer.resize(numbers.size());
    stack<int> stk;

    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        while (1)
        {
            if (stk.empty())
            {
                answer[i] = -1;
                break;
            }

            if (numbers[i] < stk.top())
            {
                cout << numbers[i] << endl;
                answer[i] = stk.top();
                break;
            }
            stk.pop();
        }
        //cout << numbers[i] << endl;
        stk.push(numbers[i]);
    }
    return answer;
}