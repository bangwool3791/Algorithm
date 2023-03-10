#include "pch.h"
#define MAX 101

int dir, ny, nx, my[] = { 0, -1, 0, 1 }, mx[] = { 1, 0, -1, 0 }, by[] = { 0, 1, 1 }, bx[] = { 1, 0, 1 }, ans = 0;
bool ch[MAX][MAX], box;

void dragon(int x, int y, int d, int g)
{
	vector<int> temp;
	temp.push_back(d);

	while (g--)
	{
		for (int i = temp.size() - 1; i >= 0; i--)
		{
			dir = temp[i] + 1;
			if (dir > 3) dir = 0;
			temp.push_back(dir);
		}
	}
	ny = y, nx = x;
	ch[ny][nx] = true;
	for (int i = 0; i < temp.size(); ++i)
	{
		ny += my[temp[i]];
		nx += mx[temp[i]];
		if (ny > 100 || ny < 0 || nx > 100 || nx < 0) continue;
		if (!ch[ny][nx]) ch[ny][nx] = true;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, x, y, d, g;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> x >> y >> d >> g;
		dragon(x, y, d, g);
	}

	for (int i = 0; i < MAX - 1; ++i)
	{
		for (int j = 0; j < MAX - 1; ++j)
		{
			y = i, x = j;
			box = false;

			if (ch[y][x])
			{
				for (int i = 0; i < 3; ++i)
				{
					ny = y + by[i];
					nx = x + bx[i];
					if (!ch[ny][nx])
					{
						box = true;
						break;
					}
				}
			}
			else
				box = true;

			if (!box) ans++;
		}
	}

	cout << ans << endl;
	return 0;
}