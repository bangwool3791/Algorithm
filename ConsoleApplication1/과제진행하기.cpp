#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct _Node
{
    string subject;
    int start;
    int Duration;
}Node;

Node arr[1001];

bool cmp(Node rhs, Node lhs)
{
    if (rhs.start < lhs.start)
        return true;
    else return false;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    stack<Node> st;

    int N = plans.size();

    for (int i = 0; i < plans.size(); ++i)
    {
        arr[i].subject = plans[i][0];
        arr[i].start = plans[i][1][0] * 600 + plans[i][1][1] * 60 + plans[i][1][3] * 10 + plans[i][1][4];
        arr[i].Duration = stoi(plans[i][2]);
    }

    sort(arr, arr + N, cmp);
    int idx = 0;
    Node cur;
    Node next = arr[idx++];

    while (idx < N)
    {
        cur = next;
        next = arr[idx++];

        int diff = next.start - cur.start;

        if (diff >= cur.Duration)
        {
            diff -= cur.Duration;
            answer.push_back(cur.subject);

            while (diff > 0 && !st.empty())
            {
                Node StackData = st.top();
                st.pop();

                if (diff >= StackData.Duration)
                {
                    diff -= StackData.Duration;
                    answer.push_back(StackData.subject);
                }
                else
                {
                    StackData.Duration -= diff;
                    diff = 0;
                    st.push(StackData);
                }
            }
        }
        else
        {
            cur.Duration -= diff;
            st.push(cur);
        }
    }

    answer.push_back(arr[N - 1].subject);

    while (!st.empty())
    {
        answer.push_back(st.top().subject);
        st.pop();
    }
    return answer;
}