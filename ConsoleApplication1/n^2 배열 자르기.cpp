#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; ++i)
    {
        int a = i / n > i % n ? i / n : i % n;
        answer.push_back(a + 1);
    }
    return answer;
}