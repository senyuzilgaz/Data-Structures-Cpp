#include <vector>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
	vector<int> results) {
	unordered_map<string, int> teams;
	pair<string, int> max;
	int temp;
	max.second = INT_MIN;

	for (int i = 0; i < competitions.size(); ++i)
	{
		if (results[i])
		{
			teams[competitions[i][0]] += 1;
			temp = teams[competitions[i][0]];
			if (temp > max.second)
				max = { competitions[i][0], temp };
		}
		else
		{
			teams[competitions[i][1]] += 1;
			temp = teams[competitions[i][1]];
			if (temp > max.second)
				max = { competitions[i][1], temp };
		}
	}
	return max.first;

}
