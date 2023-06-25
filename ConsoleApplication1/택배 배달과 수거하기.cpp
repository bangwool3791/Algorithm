#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 트럭을 두개로 생각해보자

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
	long long answer = -1;
	long long result = 0;

	int dis = deliveries.size() - 1;

	while (dis != -1)
	{
		int truck_start = cap;
		int truck_end = cap;

		for (int i = dis; i >= 0; --i)
		{
			if (deliveries[i] > truck_start)
			{
				deliveries[i] -= truck_start;
				truck_start = 0;
			}
			else
			{
				truck_start -= deliveries[i];
				deliveries[i] = 0;
			}
			if (truck_start == 0) { break; }
		}

		for (int i = dis; i >= 0; --i)
		{
			if (pickups[i] > truck_end)
			{
				pickups[i] -= truck_end;
				truck_end = 0;
				break;
			}
			else
			{
				truck_end -= pickups[i];
				pickups[i] = 0;
			}
		}

		if (!(truck_start == cap && truck_end == cap))
		{
			result = result + (dis + 1) * 2;
		}

		for (int i = dis; i >= 0; --i)
		{
			if (deliveries[i] == 0 && pickups[i] == 0) { dis--; }
			else { break; }
		}
	}

	answer = result;
	return answer;
}