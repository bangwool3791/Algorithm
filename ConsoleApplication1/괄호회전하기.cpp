#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;

    queue<char> que;

    for (int j = 0; j < s.size(); ++j)
        que.push(s[j]);

    int idx = s.size();

    if (idx == 1)
        return 0;

    while (idx > 0)
    {
        queue<char> tmp = que;
        stack<char> memo;

        while (!tmp.empty())
        {
            char ch = tmp.front();

            if (ch == '[' || ch == '{' || ch == '(')
            {
                memo.push(ch);
            }
            else
            {
                if (memo.empty())
                    break;

                if (memo.top() == '[' && ch != ']')
                    break;

                if (memo.top() == '{' && ch != '}')
                    break;

                if (memo.top() == '(' && ch != ')')
                    break;

                memo.pop();
            }
            tmp.pop();
        }

        if (tmp.empty() && memo.empty())
            ++answer;

        --idx;
        char top = que.front();
        que.pop();
        que.push(top);
    }

    return answer;
}