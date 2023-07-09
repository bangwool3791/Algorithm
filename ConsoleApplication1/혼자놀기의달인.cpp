#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;

    int nextnode = 0;
    vector<int> copydp = vector<int>(cards.size(), 0);

    for (int i = 0; i < cards.size(); ++i)
    {
        vector<int> dp = vector<int>(cards.size(), 0);
        int a = 0;

        nextnode = cards[i] - 1;

        while (dp[nextnode] == 0)
        {
            dp[nextnode] = 1;
            nextnode = cards[nextnode] - 1;
            ++a;
        }

        copydp = dp;

        for (int j = 0; j < cards.size() && copydp[j] == 0; ++j)
        {
            int b = 0;
            nextnode = cards[j] - 1;

            while (copydp[nextnode] == 0)
            {
                copydp[nextnode] = 1;
                nextnode = cards[nextnode] - 1;
                ++b;
            }
            answer = max(answer, a * b);
            copydp = dp;
        }
    }

    return answer;
}