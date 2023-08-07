#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

void dfs(string skill, string skill_trees, int depth, int pos)
{
    if (skill_trees.size() == pos || depth == skill.size())
    {
        cout << skill_trees << endl;
        ++answer;
        return;
    }


    if (skill[depth] != skill_trees[pos])
    {
        for (int i = depth + 1; i < skill.size(); ++i)
        {
            if (skill_trees[pos] == skill[i])
                return;
        }
    }

    if (skill[depth] == skill_trees[pos])
    {
        dfs(skill, skill_trees, depth + 1, pos + 1);
    }
    else
    {
        dfs(skill, skill_trees, depth, pos + 1);
    }
}
int solution(string skill, vector<string> skill_trees) {

    for (int j = 0; j < skill_trees.size(); ++j)
    {
        dfs(skill, skill_trees[j], 0, 0);
    }
    return answer;
}