#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int k = 0;

    vector<int> vec;

    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int n;
        cin >> n;
        vec.push_back(n);
    }

    sort(vec.begin(), vec.end());

    int answer = 0;
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j <= i; ++j)
        answer += vec[j];
    }
    cout << answer << endl;
    return 0;
}