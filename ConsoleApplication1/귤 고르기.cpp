#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> lhs, vector<int> rhs)
{
    if (lhs.size() > rhs.size())
        return true;
    else
        return false;
}
int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    vector<vector<int>> bucket = vector<vector<int>>(10'000'001);

    for (int i = 0; i < tangerine.size(); ++i)
    {
        bucket[tangerine[i]].push_back(tangerine[i]);
    }

    sort(bucket.begin(), bucket.end(), cmp);

    int idx = 0;
    while (k > 0)
    {
        ++answer;
        for (int i = 0; i < bucket[idx].size(); ++i)
        {
            --k;

            if (k == 0)
                break;
        }
        ++idx;
    }
    return answer;
}