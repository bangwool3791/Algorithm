#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int answer = 987654321;

void dfs(string s, int depth)
{
    if (s.size() == depth)
        return;

    string str = s;
    string token = str.substr(0, depth);

    string result = "";
    string tmp;

    int cnt = 0;

    while (true)
    {
        tmp = str.substr(0, depth);

        if (tmp == token)
            ++cnt;
        else
        {
            if (cnt > 1)
                result += std::to_string(cnt);

            result += token;
            cnt = 1;
        }
        token = tmp;
        str = str.substr(depth);

        if (str.size() < depth)
        {
            if (cnt > 1)
                result += std::to_string(cnt);

            result += token;
            result += str;
            break;
        }
    }

    dfs(s, depth + 1);
    answer = min(answer, (int)result.size());
    return;
}
int solution(string s) {
    if (s.size() == 1)
        return 1;

    dfs(s, 1);

    return answer;
}