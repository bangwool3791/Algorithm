#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end(), cmp);

    int last = -1;

    for (auto t : targets) {
        if (t[0] < last && t[1] >= last)
            continue;
        else {
            last = t[1];
            answer++;
        }
    }
    return answer;
}