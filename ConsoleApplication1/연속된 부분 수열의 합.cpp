//My code
//#include <string>
//#include <vector>
//
//using namespace std;
//
//#define INF 987654321
//
//long long cal(vector<int> sequence, int sum, int& n, int k)
//{
//    sum += sequence[n];
//
//    if (sum >= k)
//    {
//        return sum;
//    }
//
//    if (n == sequence.size() - 1)
//    {
//        sum += sequence[n];
//        return sum;
//    }
//
//    n += 1;
//
//    return cal(sequence, sum, n, k);
//}
//
//vector<int> answer;
//
//vector<int> solution(vector<int> sequence, int k) {
//
//    answer.resize(2);
//    answer[0] = 0;
//    answer[1] = INF;
//
//    long long minValue = INF;
//    int index = 0;
//
//    for (int i = 0; i < sequence.size(); ++i)
//    {
//        long long result = 0;
//
//        index = i;
//
//        result = cal(sequence, result, index, k);
//
//        if (result == k && index - i < answer[1] - answer[0])
//        {
//            answer[0] = i;
//            answer[1] = index;
//
//            if (sequence[0] == sequence[sequence.size() - 1])
//                return answer;
//        }
//    }
//    return answer;
//}

#include "pch.h"

using namespace std;

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    int s = 0, e = 0;
    int sublen = sequence.size() + 1;
    int sum = sequence[0];

    pair<int, int> answer;

    while (s <= e && e < sequence.size())
    {
        if (sum < k)
        {
            sum += sequence[++e];
        }
        else if (sum == k)
        {
            if (e - s + 1 < sublen)
            {
                sublen = e - s + 1;
                answer = { s, e };
            }
            else if (e - s + 1 == sublen)
            {
                if (s < answer.first)
                {
                    answer = { s, e };
                }
            }
            sum -= sequence[s++];
        }
        else if (sum > k)
        {
            sum -= sequence[s++];
        }
    }

    return { answer.first, answer.second };
}

int main()
{
    vector<int> sequence;
    int k = 0;

    for (int i = 0; i < 5; ++i)
    {
        int n = 0;
        cin >> n;
        sequence.push_back(n);
    }

    cin >> k;

    solution(sequence, k);

    cout << answer[0] << ' ' << answer[1] << endl;
    return 0;
}