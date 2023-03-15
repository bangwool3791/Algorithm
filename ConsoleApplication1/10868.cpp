#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 1;
const int INF = 1e9 + 1;
//데이터 배열
long long arr[MAX];
//트리 배열
long long segmentTree[4 * MAX];

//트리 초기화
long long initializeSegmentTree(int left, int right, int node)
{
	/*
	* leaf 노드이면
	* left = 1 and right = 2 일 때
	* mid = 1 이므로, 
	* 다음 재귀에서 (1,1) (2,2) 호출
	*/
	
	if (left == right)
	{
		return segmentTree[node] = arr[left];
	}

	//left 노드가 아니면 미드를 구한다.
	int mid = (left + right) / 2;
	//자식 노드 초기화 후 작은 노드를 부모로 만든다.
	return segmentTree[node] = min(initializeSegmentTree(left, mid, node * 2), initializeSegmentTree(mid + 1, right, node * 2 + 1));
}

/*
* 특정 구간에서 최소 값을 조회하는 함수 
*/
long long query(int left, int right, int node, int nodeLeft, int nodeRight)
{
	//범위 밖이면 무한 리턴
	if (nodeLeft > right || nodeRight < left)
	{
		return INF;
	}

	/*
	* left 3 right 5
	* 2로 분할 해가며 작은 값을 탐색
	* left right 범위 안에 있는 노드는 자기 자신의 값을 리턴한다.
	* nodeleft = 3, 4, 5
	* noderight = 3 ,4 ,5
	*/
	if (nodeLeft >= left && right >= nodeRight)
	{
		return segmentTree[node];
	}

	int mid = (nodeLeft + nodeRight) / 2;

	return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	initializeSegmentTree(1, N, 1);

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << query(a, b, 1, 1, N) << "\n";
	}

	return 0;
}