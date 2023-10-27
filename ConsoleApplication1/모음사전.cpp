#include <string>
#include <vector>
#include <iostream>

using namespace std;

char mou[5] = { 'A','E','I','O','U' };
vector<string> dic;

void dfs(string word, int n)
{
    if (n == 5)
        return;

    for (int i = 0; i < 5; ++i)
    {
        word[n] = mou[i];
        dic.push_back(word.substr(0, n + 1));
        dfs(word, n + 1);
    }
}

int solution(string word) {
    int answer = 0;
    string param;
    param.resize(5);
    dfs(param, 0);

    for (int i = 0; i < dic.size(); ++i)
    {
        if (dic[i] == word)
            return i + 1;
    }
    return answer;
}