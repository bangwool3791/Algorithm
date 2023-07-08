#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> assist;
    int box = 1;
    int k = 0;

    for (int box = 1; k < order.size() && box <= 1'000'000; ++box)
    {
        if (box == order[k])
        {
            ++k;
            ++answer;
        }
        else
        {
            assist.push(box);
        }

        while (!assist.empty() && assist.top() == order[k])
        {
            ++k;
            assist.pop();
            ++answer;
        }
    }
    return answer;
}