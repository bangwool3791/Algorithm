#include "pch.h"

#define MAX 1000001

long long* tree;
long long arr[MAX];

int init(int node, int start, int end)
{
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;

    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int sum(int node, int start, int end, int left, int right)
{
    /*
    * 예외처리 1
    * 조건 sum(node * 2, start, mid, left, right) -> end가 left보다 작아 진다.
    * 조건 sum(node * 2 + 1, mid + 1, end, left, right) -> start가 right보다 커진다.
    */
    if (left > end || right < start) return 0;

    /*
    * 자식 노드가 합산 범위에 있으면 
    */
    if (left <= start && end <= right) return tree[node];

    /*
    * 아래 자식 노드 sum 실행한다.
    */
    int mid = (start + end) / 2;

    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, int diff)
{
    //노드가 인덱스를 벗어나면
    if (index < start || index > end) return;

    tree[node] += diff;

    //시작과 끝이 같다면 리턴
    if (start == end) return;

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, diff);
    update(node * 2 + 1, mid + 1, end, index, diff);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num, m, k, a, b, c;

    cin >> num >> m >> k;

    for (int i = 0; i < num; ++i)
        cin >> arr[i];

    int height = ceil(log2(num));

    tree = new long long[1 << (height + 1)];

    init(1, 0, num - 1);

    for (int i = 0; i < m + k; ++i)
    {
        cin >> a >> b >> c;

        if (1 == a)
        {
            long long diff = c - arr[b - 1];
            arr[b - 1] = c;
            update(1, 0, num - 1, b - 1, diff);
        }
        else if (2 == a)
        {
            cout << sum(1, 0, num - 1, b - 1, c - 1) << endl;
        }
    }
    return 0;
}