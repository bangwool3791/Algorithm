#include "pch.h"

/*
* 1.
* 1 카메라 -> 영역 표시 -> 4 방향 -> 영역 해지
* 2 카메라 -> 영역 표시 -> 2 방향 -> 영역 해지
* 3 카메라 -> 영역 표시 -> 4 방향 -> 영역 해지
* 4 카메라 -> 영역 표시 -> 2 방향 -> 영역 해지
* 5 카메라 -> 영역 표시 -> 1 방향 -> 영역 해지
* 
* stack 자료형 <카메라 종류, 위치>
*/

/*
* 4방향 감시 가능한 영역 만든다.
* 카메라 -> 방향 -> 감시 함수 호출
* dfs -> 첫번째 카메라(1) -> 다음 카메라(1) -> 다음 카메라(1) ... -> 마지막 카메라 
*/

/*
* -1 물줄기
*/
#define ll long long
#define INF 1e9

int ans = 987654321;
int n, m;
int room[9][9];
int cctv;
int cctvs[8] = { 0, };
int cctvDir[6] = { 0,4,2,4,4,1 };
pair<int, int> coord[6][8];

int count()
{
	int cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (room[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

void checkUp(int r, int c, int checked[9][9])
{
	for (int i = r; i >= 1; --i)
	{
		if (room[i][c] == 6) break;
		else if (room[i][c] == 0)
		{
			room[i][c] = 1;
			checked[i][c] = 9;
		}
	}
	return;
}

void checkDown(int r, int c, int checked[9][9])
{
	for (int i = r; i <= n; ++i)
	{
		if (room[i][c] == 6) break;
		else if (room[i][c] == 0)
		{
			room[i][c] = 1;
			checked[i][c] = 9;
		}
	}
	return;
}

void checkLeft(int r, int c, int checked[9][9])
{
	for (int i = c; i >= 1; --i)
	{
		if (room[r][i] == 6) break;
		else if (room[r][i] == 0)
		{
			room[r][i] = 1;
			checked[r][i] = 9;
		}
	}
	return;
}

void checkRight(int r, int c, int checked[9][9])
{
	for (int i = c; i <= m; ++i)
	{
		if (room[r][i] == 6) break;
		else if (room[r][i] == 0)
		{
			room[r][i] = 1;
			checked[r][i] = 9;
		}
	}
	return;
}

void camera1(int dir, int checked[9][9], int order)
{
	pair<int, int> p = coord[1][order];
	int r = p.first;
	int c = p.second;

	switch (dir)
	{
	case 0:
		checkUp(r, c, checked);
		break;
	case 1:
		checkRight(r, c, checked);
		break;
	case 2:
		checkDown(r, c, checked);
		break;
	case 3:
		checkLeft(r, c, checked);
		break;
	}
	return;
}

void camera2(int dir, int checked[9][9], int order)
{
	pair<int, int> p = coord[2][order];
	int r = p.first;
	int c = p.second;

	switch (dir)
	{
	case 0:
		checkRight(r, c, checked);
		checkLeft(r, c, checked);
		break;
	case 1:
		checkUp(r, c, checked);
		checkDown(r, c, checked);
		break;
	}
	return;
}

void camera3(int dir, int checked[9][9], int order)
{
	pair<int, int> p = coord[3][order];
	int r = p.first;
	int c = p.second;

	switch (dir)
	{
	case 0:
		checkUp(r, c, checked);
		checkLeft(r, c, checked);
		break;
	case 1:
		checkLeft(r, c, checked);
		checkDown(r, c, checked);
		break;
	case 2:
		checkDown(r, c, checked);
		checkRight(r, c, checked);
		break;
	case 3:
		checkRight(r, c, checked);
		checkUp(r, c, checked);
		break;
	}
	return;
}

void camera4(int dir, int checked[9][9], int order)
{
	pair<int, int> p = coord[4][order];
	int r = p.first;
	int c = p.second;

	switch (dir)
	{
	case 0:
		checkRight(r, c, checked);
		checkUp(r, c, checked);
		checkLeft(r, c, checked);
		break;
	case 1:
		checkUp(r, c, checked);
		checkLeft(r, c, checked);
		checkDown(r, c, checked);
		break;
	case 2:
		checkLeft(r, c, checked);
		checkDown(r, c, checked);
		checkRight(r, c, checked);
		break;
	case 3:
		checkDown(r, c, checked);
		checkRight(r, c, checked);
		checkUp(r, c, checked);
		break;
	}
	return;
}

void camera5(int dir, int checked[9][9], int order)
{
	pair<int, int> p = coord[5][order];
	int r = p.first;
	int c = p.second;

	checkRight(r, c, checked);
	checkUp(r, c, checked);
	checkLeft(r, c, checked);
	checkDown(r, c, checked);

	return;
}

void camera(int type, int dir, int checked[9][9], int order)
{
	switch (type)
	{
	case 1:
		camera1(dir, checked, order);
		break;
	case 2:
		camera2(dir, checked, order);
		break;
	case 3:
		camera3(dir, checked, order);
		break;
	case 4:
		camera4(dir, checked, order);
		break;
	case 5:
		camera5(dir, checked, order);
		break;
	}
}

void view(int type, int dir, int checked[9][9], int order)
{
	camera(type, dir, checked, order);
	return;
}

void unView(int type, int dir, int checked[9][9])
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (checked[i][j] == 9) {
				room[i][j] = 0;
			}
		}
	}
	return;
}

void dfs(int depth)
{
	if (depth == cctv)
	{
		int cnt = count();
		ans = min(ans, cnt);
		return;
	}

	int order = depth;
	int type = cctvs[order];
	int dir = cctvDir[type];
	for (int i = 0; i < dir; ++i)
	{
		int checked[9][9];
		memset(checked, 0, sizeof(checked));

		view(type, i, checked, order);
		dfs(depth + 1);
		unView(type,i,checked);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> room[i][j];
			if (1 <= room[i][j] && room[i][j] <= 5)
			{
				cctvs[cctv] = room[i][j];
				coord[room[i][j]][cctv] = make_pair(i, j);
				cctv++;
			}
		}
	}

	dfs(0);

	cout << ans << '\n';

	return 0;
}