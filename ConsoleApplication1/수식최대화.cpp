#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

long long answer;
bool DP[3];
vector<char> operater, priority;
vector<long long> digit;
map<int, char> oper_type;

long long calculate(long long A, long long B, char oper)
{
    if (oper == '+') return A + B;
    if (oper == '-') return A - B;
    if (oper == '*') return A * B;
}

long long find_result()
{
    vector<char> oper = operater;
    vector<long long> numbers = digit;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < oper.size(); ++j)
        {
            if (priority[i] == oper[j])
            {
                long long result = calculate(numbers[j], numbers[j + 1], oper[j]);
                numbers[j] = result;
                numbers.erase(numbers.begin() + j + 1);
                oper.erase(oper.begin() + j);
                --j;
            }
        }
    }
    return abs(numbers[0]);
}

void setting(string exp)
{
    oper_type[0] = '*';
    oper_type[1] = '+';
    oper_type[2] = '-';

    string num = "";

    for (int i = 0; i < exp.size(); ++i)
    {
        if (isdigit(exp[i]) == 0)
        {
            digit.push_back(stoll(num));
            operater.push_back(exp[i]);
            num = "";
        }
        else
        {
            num += exp[i];
        }
    }
    digit.push_back(stoll(num));
}

void DFS(int cnt)
{
    if (cnt == 3)
    {
        long long result = find_result();
        answer = max(result, answer);
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            if (DP[i]) continue;
            DP[i] = true;
            priority.push_back(oper_type[i]);
            DFS(cnt + 1);
            priority.pop_back();
            DP[i] = false;
        }
    }
}

long long solution(string expression) {

    setting(expression);
    DFS(0);
    return answer;
}