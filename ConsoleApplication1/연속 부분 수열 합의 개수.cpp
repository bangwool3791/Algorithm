#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;

    int len = elements.size();
    vector<int> copyelement(elements);
    set<int> setanswer;

    copy(copyelement.begin(), copyelement.end(), back_inserter(elements));

    for (int start = 0; start < len; ++start)
    {
        int sum = elements[start];
        setanswer.insert(sum);
        int cnt = 1;
        int end = start;

        while (cnt < len)
        {
            cnt += 1;
            end += 1;
            sum += elements[end];
            setanswer.insert(sum);
        }
    }
    return setanswer.size();
}