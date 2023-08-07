#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string str)
{
    stack<char> st;

    for (auto s : str)
    {
        if (s == '(')
            st.push(s);
        else
        {
            if (st.empty())
                return false;
            else
            {
                st.pop();
            }
        }
    }
    return true;
}

string solution(string p) {
    if (p.empty()) return p;
    string answer = "";
    int l = 0, r = 0;
    string u = "", v = "";

    for (int i = 0; i < p.size(); ++i)
    {
        if (p[i] == '(')
            ++l;
        else
            ++r;

        if (l == r)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (check(u))
    {
        answer = u + solution(v);
    }
    else
    {
        answer = "(" + solution(v) + ")";

        for (int i = 1; i < u.size() - 1; ++i)
        {
            answer += u[i] == '(' ? ')' : '(';
        }
    }
    return answer;
}