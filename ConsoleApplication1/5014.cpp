#include "pch.h"

#define MAX 1000001

queue<int>  que;
vector<int> dir;
bool checked[MAX];
int path[MAX];
int F, S, G, U, D;

void bfs(int _S)
{
	checked[_S] = true;
	que.push(_S);

	while (que.size())
	{
		int data = que.front();

		que.pop();

		for (int i{}; i < 2; ++i)
		{
			int nx = data + dir[i];

			if (0 < nx && nx <= F)
			{
				if (!checked[nx])
				{
					checked[nx] = true;
					path[nx] = path[data] + 1;
					que.push(nx);
				}
			}
		}
	}
}

int main()
{
	memset(path, 0, sizeof(int) * MAX);

	cin >> F >> S >> G >> U >> D;

	dir.push_back(U);
	dir.push_back(-1 * D);
	
	bfs(S);

	if (path[G])
	{
		cout << path[G];
	}
	else
	{
		cout << "use the stairs";
	}

	return 0;
}