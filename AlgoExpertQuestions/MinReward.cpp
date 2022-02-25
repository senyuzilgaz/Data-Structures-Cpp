#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
  vector<int> awards(scores.size(), 1);
	int len = scores.size();
	int min = 1;
	int totalAwards = 1;
	int prevScore;
	int currentScore;
	for(int i = 1; i < scores.size(); ++i){
		if(scores[i] > scores[i-1])
			awards[i] = awards[i-1] + 1;
	}
  for(int i = scores.size()-2; i>=0; --i){
		if(scores[i] > scores[i+1])
			awards[i] = max(awards[i], awards[i+1] + 1);
	}
	return accumulate(awards.begin(), awards.end(), 0);
}
