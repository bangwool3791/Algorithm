#include "pch.h"
#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int map[25][25];
int visted[25][25];
vector<int> cntVec;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int N;
int cnt;

//void dfs(int r, int c)
//{
//	for (int i{}; i < 4; ++i)
//	{
//		int nr = r + dr[i];
//		int nc = c + dc[i];
//
//		if(nr >= N || nr < 0 || nc >= N || nc < 0)
//			continue;
//
//		if(visted[nr][nc] == 0 && map[nr][nc] == 1)
//		{
//			visted[nr][nc] = 1;
//			cnt++;
//			dfs(nr, nc);
//		}
//	}
//}
//
//int main()
//{
//	int res{};
//
//	cin >> N;
//
//	for (int i{}; i < N; ++i)
//	{
//		string temp;
//		cin >> temp;
//
//		for (int j{}; j < temp.size(); ++j)
//		{
//			map[i][j] = temp[j] - '0';
//		}
//	}
//	
//	for(int i{0}; i < N; ++i)
//	{
//		for (int j{ 0 }; j < N; ++j)
//		{
//			if (visted[i][j] == 0 && map[i][j] == 1)
//			{
//				visted[i][j] = 1;
//				cnt = 1;
//				dfs(i, j);
//				cntVec.push_back(cnt);
//				res++;
//			}
//		}
//	}
//	sort(cntVec.begin(), cntVec.end());
//	cout << res << "\n";
//
//	for (int i = 0; i < cntVec.size(); i++) {
//		cout << cntVec[i] << "\n";
//	}
//	return 0;
//}