
#include <iostream>
#include <math.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

template<typename T>
T part(T x)
{
    int sum = x;

    while (x)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int main()
{
    int n{ 0 };
    cin >> n;

    for (size_t i = 1; i < n; ++i)
    {
        if (n == part(i))
        {
            cout << i << endl;
            return i;
        }
    }
    return 0;
}

