#include "pch.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;

	map<string, int> umap;

	for (int i = 0; i < players.size(); ++i)
	{
		umap.insert(make_pair(players[i], i));
	}

	for (int i = 0; i < callings.size(); ++i)
	{
		int iBackIndex = umap[callings[i]];

		if (iBackIndex == 0 || iBackIndex == players.size())
			continue;

		string frontPlayer = players[iBackIndex - 1];
		string backPlayer = players[iBackIndex];

		players[iBackIndex] = frontPlayer;
		players[iBackIndex - 1] = backPlayer;

		umap[backPlayer] = iBackIndex - 1;
		umap[frontPlayer] = iBackIndex;
	}

	for (int i = 0; i < players.size(); ++i)
	{
		answer.push_back(players[i]);
	}

	return answer;
}