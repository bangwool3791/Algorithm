#include <string>
#include <vector>
#include <queue>
#include <cmath>
#define INF 987654321 
using namespace std;

int Distance(int x, int y)
{
    return (pow(x, 2) + pow(y, 2));
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {

    vector<int> answer;

    for (int i = 0; i < balls.size(); ++i)
    {
        int minDistance = INF;

        int goalX = balls[i][0];
        int goalY = balls[i][1];
        int reflectX = 0;
        int reflectY = 0;
        int RetDis = 0;

        //위 좌표축

        if (startX != goalX || goalY < startY)
        {
            reflectX = goalX;
            reflectY = goalY + 2 * (n - goalY);
            RetDis = Distance(startX - reflectX, startY - reflectY);
            minDistance = min(RetDis, minDistance);
        }

        //오른쪽 좌표축
        if (startY != goalY || goalX < startX)
        {
            reflectX = goalX + 2 * (m - goalX);
            reflectY = goalY;
            RetDis = Distance(startX - reflectX, startY - reflectY);
            minDistance = min(RetDis, minDistance);
        }

        //x축
        if (startX != goalX || startY < goalY)
        {
            reflectX = goalX;
            reflectY = -goalY;
            RetDis = Distance(startX - reflectX, startY - reflectY);
            minDistance = min(RetDis, minDistance);
        }

        //y축
        if (startY != goalY || startX < goalX)
        {
            reflectX = -goalX;
            reflectY = goalY;
            RetDis = Distance(startX - reflectX, startY - reflectY);
            minDistance = min(RetDis, minDistance);
        }

        answer.push_back(minDistance);
    }

    return answer;
}