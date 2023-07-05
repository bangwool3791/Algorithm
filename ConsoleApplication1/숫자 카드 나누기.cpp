#include <string>
#include <vector>
#include <cmath>

using namespace std;

int gdc(int a, int b)
{
    if (b == 0)
        return a;

    return gdc(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    int cur = arrayA[0];
    for (int i = 1; i < arrayA.size(); ++i)
    {
        cur = gdc(arrayA[i], cur);

        if (cur == 1)break;
    }

    for (int i = 0; i < arrayB.size(); ++i)
    {
        if (arrayB[i] % cur == 0)
            break;

        if (i == arrayB.size() - 1)
            answer = cur;
    }

    cur = arrayB[0];
    for (int i = 1; i < arrayB.size(); ++i)
    {
        cur = gdc(arrayB[i], cur);

        if (cur == 1)break;
    }

    for (int i = 0; i < arrayA.size(); ++i)
    {
        if (arrayA[i] % cur == 0)
            break;

        if (i == arrayA.size() - 1)
            answer = max(cur, answer);
    }
    return answer;
}