#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long elem, sum1, sum2;
    int idxleft = 0, idxright = 0, cnt = 0;
    int qSize = queue1.size();

    sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    sum2 = accumulate(queue2.begin(), queue2.end(), 0);

    long long sum = sum1 + sum2;

    if (sum % 2 != 0)
        return -1;

    while (cnt < qSize * 4)
    {
        if (sum1 == sum2)
        {
            cout << sum1 << " " << sum2 << endl;
            return cnt;
        }

        if (sum1 > sum2)
        {
            elem = idxleft < qSize ? queue1[idxleft] : queue2[idxleft - qSize];
            sum1 -= elem;
            sum2 += elem;
            ++idxleft;
            ++cnt;
        }
        else if (sum1 < sum2)
        {
            elem = idxright < qSize ? queue2[idxright] : queue1[idxright - qSize];
            sum2 -= elem;
            sum1 += elem;
            ++idxright;
            ++cnt;
        }
    }
    return -1;
}