#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int column = 0;

using namespace std;
bool cmp(vector<int> lhs, vector<int> rhs)
{
    if (lhs[column] < rhs[column])
        return true;
    else if (lhs[column] > rhs[column])
        return false;
    else
    {
        if (lhs[0] < rhs[0])
            return false;
        else if (lhs[0] > rhs[0])
            return true;
    }
}

long long make_hash(int i, vector<int> elem)
{
    long long hash_value = 0;

    for (int j = 0; j < elem.size(); ++j)
    {
        //cout << elem[j] << endl;
        hash_value += elem[j] % i;
    }
    //cout << hash_value << endl;
    return hash_value;
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    long long answer = 0;

    column = col - 1;
    sort(data.begin(), data.end(), cmp);

    //for(int i = 0; i < data.size(); ++i)
   // {
   //     for(int j= 0; j < data[i].size(); ++j)
  //      {
  //          cout << data[i][j];
  //      }
  //      cout << endl;
  //  }

    for (int i = 1; i <= data.size(); ++i)
    {
        if (row_begin <= i && i <= row_end)
        {
            answer ^= make_hash(i, data[i - 1]);
        }
    }

    //cout << answer << endl;
    return answer;
}