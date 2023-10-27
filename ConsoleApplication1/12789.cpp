#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> students = vector<int>(n + 1, 0);
    stack<int> line;
    int current = 1;
    int idx = 0;

    for (int i = 0; i < n; ++i)
        cin >> students[i];

    while (idx < n)
    {
        if (current != students[idx])
        {
            line.push(students[idx]);
        }
        else
        {
            current++;

            while (!line.empty() && line.top() == current)
            {
                line.pop();
                current++;
            }
        }

        ++idx;
    }
    if(line.empty())
        cout << "Nice" << endl;
    else
        cout << "Sad" << endl;

    return 0;
}