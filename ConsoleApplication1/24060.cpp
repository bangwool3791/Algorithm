#include <iostream>
#include <vector>

using namespace std;

int N = 0; int M = 0;
int answer = 0;
int inputcnt = 0;

void merge(vector<int>& A, int p, int q, int r, int K)
{
    int i = p;
    int j = q + 1;
    int t = 1;

    vector<int> tmp = vector<int>(r + 2);

    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
        {
            tmp[t++] = A[i++];
        }
        else
        {
            tmp[t++] = A[j++];
        }
    }

    while (i <= q)
        tmp[t++] = A[i++];
    
    while (j <= r)
        tmp[t++] = A[j++];

    t = 1;
    i = p;
    
    while (i <= r)
    {
        A[i++] = tmp[t++];

        if (++inputcnt == K)
        {
            cout << tmp[t - 1];
        }
    }

}

void merge_sort(vector<int>& A, int p, int r, int K)
{
    if (p < r)
    {
        int q = (p + r) / 2;

        merge_sort(A, p, q, K);
        merge_sort(A, q + 1, r, K);
        merge(A, p, q, r, K);
    }
}

int main()
{
    cin >> N >> M;

    vector<int> vec = vector<int>(N + 1);

    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }
    merge_sort(vec, 0, N - 1, M);
    cout << answer << endl;
    return 0;
}