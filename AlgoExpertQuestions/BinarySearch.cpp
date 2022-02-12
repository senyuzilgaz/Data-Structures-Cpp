#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
	int left=0;
	int right=array.size();
  int mid = (right+left)/2;
	int focus=0;
	
  while(1)
	{
		focus=array[mid];
		
		if(focus==target)
			return mid;		
		
		else if(focus>target)
			right = mid;
		
		else
			left=mid;
		
		if(mid == (right+left)/2)
			break;
		mid = (right+left)/2;
	}
  return -1;
}
