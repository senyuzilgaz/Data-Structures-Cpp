#include <vector>
using namespace std;
bool compareIntervals(vector<int> a, vector<int> b)
{
	return a[0] < b[0];
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
	if(intervals.size() <= 1)
		return intervals;
	int k = 0;
	
  sort(intervals.begin(), intervals.end(), compareIntervals);
	vector<vector<int>> result = {};
	
	for(int i = 1; i<intervals.size(); ++i)
	{
		if(intervals[i][0] <= intervals[i-1][1])
		{
			k = i;
			while( k<intervals.size() && intervals[k][0] <= intervals[k-1][1])
				++k;
			result.push_back( {intervals[i-1][0], max(intervals[k-1][1], intervals[i-1][1])} );
			i=k;
		}
		else
		{
			if(result.size()<1)
				result.push_back(intervals[i-1]);
			else{
				 if(result.size()>=1 && result.back()[1] < intervals[i-1][0])
					 result.push_back(intervals[i-1]);
			}
		}
	}
	if(intervals[intervals.size()-1][0] <=result[result.size()-1][1])
		result[result.size()-1] = {result[result.size()-1][0], max( result[result.size()-1][1], intervals[intervals.size()-1][1])};
	else
		result.push_back(intervals[intervals.size()-1]);
  return result;
}
