#include <string>
#include <vector>


using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1000][1000];
    int pos = 0;
    int x = 0;
    int y = 0;
    int num = 1;

    for (int i = 0; i < n; ++i)
    {
        switch (pos)
        {
        case 0:
            for (int j = i; j < n; ++j)
                arr[x++][y] = num++;

            --x;
            ++y;
            pos = 1;
            break;
        case 1:
            for (int j = i; j < n; ++j)
                arr[x][y++] = num++;

            --x;
            y -= 2;
            pos = 2;
            break;
        case 2:
            for (int j = i; j < n; ++j)
                arr[x--][y--] = num++;

            x += 2;
            y++;
            pos = 0;
            break;

        }

    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
            answer.push_back(arr[i][j]);
    }
    return answer;
}