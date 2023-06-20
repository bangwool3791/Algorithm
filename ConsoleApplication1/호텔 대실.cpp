#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int convertToInt(string str, bool isEndTime)
{
    int hour = stoi(str.substr(0, 2));
    int min = stoi(str.substr(3, 2));

    if (isEndTime)
    {
        if (min >= 50)
        {
            hour += 1;
            min -= 50;
        }
        else
        {
            min += 10;
        }
    }
    return hour * 100 + min;
}

int solution(vector<vector<string>> book_time)
{
    vector<pair<int, int>> times;

    for (int i = 0; i < book_time.size(); ++i)
    {
        int start = convertToInt(book_time[i][0], false);
        int end = convertToInt(book_time[i][1], true);
        times.push_back({ start, end });
    }

    sort(times.begin(), times.end());
    int answer = 0;
    vector<pair<int, int>> filled;

    for (pair<int, int> time : times)
    {
        vector<pair<int, int>> temp;

        for (pair<int, int> room : filled)
        {
            if (time.first < room.second)
            {
                temp.push_back(room);
            }
        }

        filled = temp;
        filled.push_back(time);

        answer = max(answer, (int)filled.size());
    }

    return answer;
}