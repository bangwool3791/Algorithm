#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class queuestack
{
public :

    int index = 0;
    queue<int> que;
    stack<int> st;
};
int main()
{
    int N = 0;
    int M = 0;

    cin >> N;
    vector<queuestack> structure = vector<queuestack>(N);
    vector<int> answer;

    for (int i = 0; i < N; ++i)
    {
        cin >> structure[i].index;
    }

    int data = 0;
    int temp = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> data;

        if (structure[i].index == 0)
            structure[i].que.push(data);
        else
            structure[i].st.push(data);
    }

    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        cin >> data;

        for (int j = 0; j < N; ++j)
        {
            if (structure[j].index == 0)
            {
                structure[j].que.push(data);
                temp = structure[j].que.front();
                structure[j].que.pop();
            }
            else
            {
                structure[j].st.push(data);
                temp = structure[j].st.top();
                structure[j].st.pop();
            }
            data = temp;
        }
        answer.push_back(temp);
    }

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << " ";
    }

    //if(answer.size() > 0)
    //    cout << answer[answer.size() - 1]; 

    return 0;
}