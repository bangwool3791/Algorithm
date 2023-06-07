#include "pch.h"

struct Point
{
	int x, y;

	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

struct cmp
{
	bool operator() (Point a, Point b)
	{
		if (a.x < b.x)
		{
			return true;
		}
		else if (a.x == b.x)
		{
			if (a.y < b.y)
				return true;
			else 
				return false;
		}else
			return false;
	}
};

int main()
{
	priority_queue<Point, vector<Point>, cmp> pq;

	int n = 0;

	cin >> n;

	int a = 0;
	int b = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		pq.push(Point(a, b));
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		Point pt = pq.top();

		cout << pt.x << pt.y << endl;
		pq.pop();
	}
}