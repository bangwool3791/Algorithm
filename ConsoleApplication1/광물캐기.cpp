#include <string>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

int energy[3][3] =
{
    {1,1,1},
    {5,1,1},
    {25,5,1}
};

map<string, int> MineralList;

int mineralSize;

int answer = 987654321;

void dfs(vector<int> picks, int location, int sum, vector<string> minerals)
{

    int sumList[3] = { 0, };
    int savePoint = 0;

    if (location >= mineralSize || picks[0] + picks[1] + picks[2] == 0)
    {
        answer = min(answer, sum);
        return;
    }

    for (int i = location; i < location + 5; ++i)
    {
        if (i >= mineralSize)
        {
            savePoint = i;
            break;
        }

        sumList[0] += energy[0][MineralList[minerals[i]]];
        sumList[1] += energy[1][MineralList[minerals[i]]];
        sumList[2] += energy[2][MineralList[minerals[i]]];
        savePoint = i;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (picks[i] != 0)
        {
            picks[i] -= 1;
            dfs(picks, savePoint + 1, sum + sumList[i], minerals);
            picks[i] += 1;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals)
{
    MineralList.insert(make_pair<string, int>("diamond", 0));
    MineralList.insert(make_pair<string, int>("iron", 1));
    MineralList.insert(make_pair<string, int>("stone", 2));

    mineralSize = minerals.size();
    dfs(picks, 0, 0, minerals);

    return answer;
}