#include "pch.h"

//0 ºóÄ­, 1 »ç°ú, 2 ¹ì
int n = 0, k = 0, l = 0;
int x = 0;
char c{};

int dx[4] = { -1 , 0, 1, 0 };
int dy[4] = { 0 , 1, 0, -1 };

vector<pair<int, char>> v{};

int m[101][101];

void Input()
{
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			m[i][j] = 0;
		}
	}

	for (int i = 0; i < k; ++i)
	{
		int _x = 0, _y = 0;
		cin >> _y >> _x;
		m[_y - 1][_x - 1] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; ++i)
	{
		cin >> x >> c;
		v.push_back({ x,c });
	}
}

int Turn(int d, char c)
{
	if ('L' == c)
	{
		if (0 == d) return 1;
		else if (1 == d) return 2;
		else if (2 == d) return 3;
		else if (3 == d) return 0;
	}
	else if ('D' == c)
	{
		if (0 == d) return 3;
		else if (1 == d) return 0;
		else if (2 == d) return 1;
		else if (3 == d) return 2;
	}
}

void Solution()
{
	int idx = 0;
	int d = 2;
	long long t = 0;
	int x = 0;
	int y = 0;
	deque<pair<int, int>> deq;
	deq.push_back({ x,y });
	m[y][x] = 2;
	/*
	* 1Á¶°Ç : ¹ìÀÌ º®¿¡ ´Ù´Ù¸£°Å³ª, ¹ìÀÌ ºÎµúÈù ¿µ¿ªÀÌ ¹ìÀÇ ¸öÀÎ °æ¿ì
	* 2Á¶°Ç : ºñ¾îÀÖ´Â °æ¿ì
	* 3Á¶°Ç : »ç°úÀÎ °æ¿ì
	* 4Á¶°Ç : 
	*/
	while (true)
	{
		++t;

		int nx = x + dx[d];
		int ny = y + dy[d];
		
		if (0 > nx || n <= nx || 0 > ny || n <= ny || 2 == m[ny][nx])
		{
			break;
		}
		else if (0 == m[ny][nx])
		{
			deq.push_front({ nx, ny });
			m[ny][nx] = 2;
			m[deq.back().second][deq.back().first] = 0;
			deq.pop_back();
		}
		else if (1 == m[ny][nx])
		{
			deq.push_front({ nx, ny });
			m[ny][nx] = 2;
		}

		if (idx < v.size())
		{
			if (t >= v[idx].first)
			{
				d = Turn(d, v[idx].second);
				++idx;
			}
		}
		x = nx;
		y = ny;
	}

	cout << t << endl;
}

int main()
{
	Input();
	Solution();
	return 0;
}