#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(),arrayTwo.end());
	int i1 = 0, i2 = 0;
	int val1, val2, absval;
	int min=INT_MAX;
	vector<int> res;
	pair<int,int> minpair;
	
	while( i1<arrayOne.size() && i2<arrayTwo.size() )
	{
		val1 = arrayOne[i1];
		val2 = arrayTwo[i2];
		if(val1 == val2){
			minpair = {val1, val2};
			break;
		}else{
			absval = abs(val1-val2);
			if(absval < min){
				min = absval;
				minpair = {val1, val2};
			}
			if(val1 > val2){
				++i2;
			}else{
				++i1;
			}
		}
	}
	res = {minpair.first, minpair.second};
  return res;
}
