#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

#define MAX 10000000001
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<long long, long long>> points;
    long long min_x = MAX;
    long long min_y = MAX;
    long long max_x = -MAX;
    long long max_y = -MAX;

    for (int i = 0; i < line.size(); ++i)
    {
        for (int j = i + 1; j < line.size(); ++j)
        {
            long long A = (long long)line[i][0];
            long long B = (long long)line[i][1];
            long long E = (long long)line[i][2];

            long long C = (long long)line[j][0];
            long long D = (long long)line[j][1];
            long long F = (long long)line[j][2];

            long long adbc = A * D - B * C;

            if (adbc == 0)
                continue;

            if ((B * F - E * D) % adbc != 0 || (E * C - A * F) % adbc != 0)
                continue;

            long long x = (B * F - E * D) / adbc;
            long long y = (E * C - A * F) / adbc;

            points.insert({ x, y });

            min_x = min(min_x, x);
            min_y = min(min_y, y);
            max_x = max(max_x, x);
            max_y = max(max_y, y);
        }
    }

    int row = max_y - min_y + 1;
    int col = max_x - min_x + 1;
    string temp(col, '.');
    answer.assign(row, temp);

    for (auto& p : points)
    {
        answer[max_y - p.second][p.first - min_x] = '*';
    }

    return answer;
}