#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <stdlib.h> 
#include <cstdlib>
using namespace std;

vector<int> solution(string s) {

    unordered_map<int, int> map;
    string str;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '{' || s[i] == ',' || s[i] == '}')
        {
            if (!str.empty())
            {
                int num = atoi(str.c_str());
                map[num]++;
                str = "";
            }
            continue;
        }

        if (isdigit(s[i]))
        {
            str += s[i];
        }
    }

    vector<int> answer(map.size());
    int size = map.size();
    for (auto iter : map)
    {
        int num = iter.second;
        answer[size - num] = iter.first;
    }

    return answer;
}