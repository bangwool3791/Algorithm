#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> towers)
{
    int count = 0;

    vector<int> visited(towers.size(), 0);

    queue<int> que;

    que.push(1);

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        if (visited[cur]) continue;

        visited[cur] = 1;
        count++;
        for (int i = 0; i < towers[cur].size(); ++i)
        {
            que.push(towers[cur][i]);
        }
    }

    int cnt2 = towers.size() - 1 - count;
    return abs(cnt2 - count);
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;

    for (int i = 0; i < wires.size(); ++i)
    {
        vector<vector<int>> towers(n + 1);

        for (int j = 0; j < wires.size(); ++j)
        {
            if (i == j)
                continue;

            int start = wires[j][0];
            int end = wires[j][1];
            towers[start].push_back(end);
            towers[end].push_back(start);
        }

        answer = min(answer, bfs(towers));
        towers.clear();
    }

    return answer;
}