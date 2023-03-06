#include "pch.h"

#define INF 987654321

int dx[6] = { -1, 1, 0, 0 , 0, 0};
int dy[6] = { 0, 0, -1, 1 , 0, 0};
int dz[6] = { 0, 0,  0,  0 ,-1, 1 };
struct Vec3
{
	int x = 0;
	int y = 0;
	int z = 0;
};

queue<Vec3> que;


int M = 0, N = 0, H = 0;
int v[100][100][101];
long long dist[100][100][101];

void input()
{
	int data = 0;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				cin >> v[i][j][k];

				if (v[i][j][k] == 0)
					dist[i][j][k] = -1;

				if (v[i][j][k] == 1)
					que.push({ k,j,i });

			}
		}
	}
}

long long Check()
{
	long long result = 0;

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (-1 == dist[i][j][k])
				{
					return -1;
				}

				result = max(result, dist[i][j][k]);
			}
		}
	}
	return result;
}

void bfs(int x, int y, int z)
{
}

int main()
{
	cin >> M >> N >> H;

	input();
	
	int x = 0, y = 0, z = 0;

	while (!que.empty())
	{
		x = que.front().x;
		y = que.front().y;
		z = que.front().z;
		que.pop();

		for (int i = 0; i < 6; ++i)
		{
			int _x = x + dx[i];
			int _y = y + dy[i];
			int _z = z + dz[i];

			if (-1 < _x && _x < M && -1 < _y && _y < N && -1 < _z && _z < H)
			{
				if (0 == v[_z][_y][_x])
				{
					v[_z][_y][_x] = 1;
					dist[_z][_y][_x] = dist[z][y][x] + 1;
					que.push({ _x,_y, _z });
				}
			}
		}
	}

	cout << Check() << endl;
	return 0;
}