#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> g_answer;
int g_maxGap;

bool compLastScore(const vector<int>& lion)
{
    for (int i = 10; i >= 0; --i)
    {
        if (lion[i] > g_answer[i]) return true;
        if (lion[i] < g_answer[i]) return false;
    }
    return true;
}

void calMaxGap(vector<int>& lion, vector<int>& apeach)
{
    int lionScore = 0;
    int apeachScore = 0;

    for (int i = 0; i < apeach.size(); ++i)
    {
        if (lion[i] > 0 || apeach[i] > 0)
        {
            if (lion[i] > apeach[i])
            {
                lionScore += 10 - i;
            }
            else
            {
                apeachScore += 10 - i;
            }
        }
    }

    int gap = lionScore - apeachScore;

    if (gap > 0 && ((gap > g_maxGap) || gap == g_maxGap && compLastScore(lion)))
    {
        cout << gap << " " << g_maxGap << endl;

        g_maxGap = gap;
        g_answer = lion;
    }
}

void dfs(vector<int>& lion, vector<int>& apeach, int depth, int arrowCnt)
{

    if (depth == 10 || arrowCnt == 0)
    {
        if (arrowCnt > 0)
        {
            lion[10] += arrowCnt;
        }
        calMaxGap(lion, apeach);

        if (arrowCnt > 0)
        {
            lion[10] -= arrowCnt;
        }
        return;
    }

    if (arrowCnt >= apeach[depth] + 1)
    {
        lion[depth] = apeach[depth] + 1;
        dfs(lion, apeach, depth + 1, arrowCnt - lion[depth]);
    }

    lion[depth] = 0;
    dfs(lion, apeach, depth + 1, arrowCnt);
}


vector<int> solution(int n, vector<int> info) {
    vector<int> lion = vector<int>(11, 0);
    dfs(lion, info, 0, n);

    if (g_answer.empty())
    {
        g_answer.push_back(-1);
    }
    return g_answer;
}