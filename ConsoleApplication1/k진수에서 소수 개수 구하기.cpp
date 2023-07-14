#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(long long n)
{ // 소수 판별
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int> arr;

    while (n != 0)
    {
        arr.push_back(n % k);
        n = n / k;
    }

    long long number = 0;

    for (int i = arr.size() - 1; i >= 0; --i)
        number = number * 10 + arr[i];

    string str = std::to_string(number);

    while (str.find('0') != std::string::npos)
    {
        size_t size = str.find('0');

        string PrimeNum = str.substr(0, size);

        str = str.substr(size + 1, str.size());
        cout << PrimeNum << endl;

        if (PrimeNum.size() > 0)
        {
            if (IsPrime(stoll(PrimeNum)))
            {
                ++answer;
            }
        }
    }

    if (str.size() > 0)
    {
        string PrimeNum = str.substr(0, str.size());
        cout << PrimeNum << endl;

        if (PrimeNum.size() > 0)
        {
            if (IsPrime(stoll(PrimeNum)))
            {
                ++answer;
            }
        }
    }
    return answer;
}