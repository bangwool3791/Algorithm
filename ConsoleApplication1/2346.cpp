#include <deque>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    deque<int> deq;
    int N;
    cin >> N;

    int data = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> data;
        deq.push_back(data);
    }

    int M = deq.front();
    deq.pop_front();

    cout << M << " ";

    while (deq.size() > 0)
    {
        if (M > 0)
        {
            for (int i = 0; i < abs(M) - 1; ++i)
            {
                int front = deq.front();
                deq.pop_front();
                deq.push_back(front);
            }

            cout << deq.front() << " ";
            deq.pop_front();

        }
        else if (M < 0)
        {
            for (int i = 0; i < abs(M) - 1; ++i)
            {
                int back = deq.back();
                deq.pop_back();
                deq.push_front(back);
            }
            cout << deq.back() << " ";
            deq.pop_back();
        }
    }
    return 0;
}