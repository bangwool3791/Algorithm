#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;

    cin >> n;
    vector<vector<int>> triangle = vector<vector<int>>(n , vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i + 1; ++j)
            cin >> triangle[i][j];


    for (int i = 1; i < triangle.size(); ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0)
                triangle[i][j] = triangle[i - 1][0] + triangle[i][j];
            else if (i == j)
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
            else
                triangle[i][j] = max(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
        }
    }
    int answer = 0;
    for (int i = 0; i < n; ++i)
        answer = max(answer, triangle[n - 1][i]);

    cout << answer << endl;
    return 0;
}