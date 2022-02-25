#include <vector>
using namespace std;

int laptopRentals(vector<vector<int>> times) {
	if(times.size() == 0)
		return 0;
  vector<int> startTimes;
	vector<int> endTimes;
	int count = 0;
	for(auto interval : times){
		startTimes.push_back(interval[0]);
		endTimes.push_back(interval[1]);
	}
	sort(startTimes.begin(), startTimes.end());
	sort(endTimes.begin(), endTimes.end());
	int startIndex = 0;
	int endIndex = 0;
	while(startIndex < times.size()){
		if(startTimes[startIndex] >= endTimes[endIndex]){
			--count;
			++endIndex;
		}
			++count;
			++startIndex;
	}
	return count;
}
