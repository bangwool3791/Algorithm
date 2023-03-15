#include "pch.h"

#define INF 1000000001

struct minimumTree
{
    int n = 0;
    vector<long long> minTree;

    minimumTree(const vector<long long>& array)
    {
        n = array.size();
        minTree.resize(n * 4);
        init(array, 0, n - 1, 1);
    }

    long long init(const vector<long long>& array, int left, int right, int node)
    {
        if (left == right)
        {
            return minTree[node] = array[left];
        }

        int mid = (left + right) / 2;
        long long leftSubTree = init(array, left, mid, node * 2);
        long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);

        return minTree[node] = min(leftSubTree, rightSubTree);
    }

    long long query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (right < nodeLeft || left > nodeRight)
            return INF;

        if (left <= nodeLeft && nodeRight <= right)
            return minTree[node];

        int mid = (nodeLeft + nodeRight) / 2;

        return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    long long update(int index, int newValue, int node, int nodeLeft, int nodeRight)
    {
        if (index < nodeLeft || index > nodeRight)
            return minTree[node];

        if (nodeLeft == nodeRight)
            return minTree[node] = newValue;

        int mid = (nodeLeft + nodeRight) / 2;

        return minTree[node] = min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }

    long long query(int left, int right)
    {
       return query(left, right, 1, 0, n - 1);
    }

    long long update(int index, int newValue)
    {
        return update(index, newValue, 1, 0, n - 1);
    }
};

struct maximumTree
{
    int n = 0;
    vector<long long> maxTree;

    maximumTree(const vector<long long>& array)
    {
        n = array.size();
        maxTree.resize(n * 4);
        init(array, 0, n - 1, 1);
    }

    long long init(const vector<long long>& array, int left, int right, int node)
    {
        if (left == right)
        {
           return maxTree[node] = array[left];
        }

        int mid = (left + right) / 2;
        long long leftSubTree = init(array, left, mid, node * 2);
        long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);

        return maxTree[node] = max(leftSubTree, rightSubTree);
    }

    long long query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (right < nodeLeft || left > nodeRight)
            return -1;

        if (left <= nodeLeft && nodeRight <= right)
            return maxTree[node];

        int mid = (nodeLeft + nodeRight) / 2;

        return max(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    long long update(int index, int newValue, int node, int nodeLeft, int nodeRight)
    {
        if (index < nodeLeft || index > nodeRight)
            return maxTree[node];

        if (nodeLeft == nodeRight)
            return maxTree[node] = newValue;

        int mid = (nodeLeft + nodeRight) / 2;

        return maxTree[node] = max(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }

    long long query(int left, int right)
    {
        return query(left, right, 1, 0, n - 1);
    }

    long long update(int index, int newValue)
    {
        return update(index, newValue, 1, 0, n - 1);
    }
};

int N, M;

int main(void)
{
    ios_base::sync_with_stdio(0);

    cin.tie(0); //cin 속도 향상 위해

    cin >> N >> M;

    vector<long long> data;
    data.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> data[i];
    
    minimumTree minTree(data);
    maximumTree maxTree(data);

    int a, b;

    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        cout << minTree.query(a - 1, b - 1) << " " << maxTree.query(a - 1, b - 1) << endl;
    }
    return 0;

}