#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> map;

void fill(string* s, string value)
{
    for (int i = 0; i < 16; ++i)
    {
        string str = "";
        int num = i;

        for (int j = 3; j >= 0; --j)
        {
            if (num <= 0 || num % 2 == 0)
                str = "-" + str;
            else
                str = s[j] + str;

            num /= 2;
        }
        map[str].push_back(atoi(value.c_str()));
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string s[4], value;

    for (int i = 0; i < info.size(); ++i)
    {
        istringstream ss(info[i]);
        ss >> s[0] >> s[1] >> s[2] >> s[3] >> value;
        fill(s, value);
    }

    for (auto iter = map.begin(); iter != map.end(); ++iter)
    {
        sort(iter->second.begin(), iter->second.end());
    }

    for (int i = 0; i < query.size(); ++i)
    {
        istringstream ss(query[i]);
        ss >> s[0] >> value >> s[1] >> value >> s[2] >> value >> s[3] >> value;

        vector<int> vec = map[s[0] + s[1] + s[2] + s[3]];

        if (!vec.empty())
        {
            int idx = lower_bound(vec.begin(), vec.end(), atoi(value.c_str())) - vec.begin();
            answer.push_back(vec.size() - idx);
        }
        else
        {
            answer.push_back(0);
        }
    }

    return answer;
}