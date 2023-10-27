#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    
    cin >> n;
        
    vector<vector<int>> DP = vector<vector<int>>(n + 1, vector<int>(4, 0));
    
    int r,g,b;
    
    for(int i = 1; i <= n; ++i)
    {
        cin >> r >> g >> b;
        DP[i][0] += min(DP[i - 1][1], DP[i - 1][2]) + r;
        DP[i][1] += min(DP[i - 1][0], DP[i - 1][2]) + g;
        DP[i][2] += min(DP[i - 1][0], DP[i - 1][1]) + b;
    }
    
    cout << min(min(DP[n][0], DP[n][1]), DP[n][2]) << endl;
    return 0;
}