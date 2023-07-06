#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> graph;

    int x = 0;

    while (1)
    {
        graph.push_back(k);

        if (k == 1)
            break;

        if (k % 2 == 0)
            k = k / 2;
        else
            k = k * 3 + 1;
    }

    int start = 0;
    int end = graph.size() - 1;

    for (int i = 0; i < ranges.size(); ++i)
    {
        int s = start + ranges[i][0];
        int e = end + ranges[i][1];

        if (e < s)
        {
            answer.push_back(-1);
            continue;
        }

        double dArea = 0.f;

        for (int j = s; j < e; ++j)
        {
            dArea += (double)(graph[j] + graph[j + 1]) * 0.5f;
        }
        answer.push_back(dArea);
    }

    return answer;
}