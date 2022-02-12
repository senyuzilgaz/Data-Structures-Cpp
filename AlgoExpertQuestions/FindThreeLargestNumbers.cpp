#include <vector>
using namespace std;


pair<int,int> findMin(vector<int> arr)
{
	if( (arr[0] <= arr[1]) && (arr[0]<=arr[2]) )
		return 0;
	if( (arr[1] <= arr[0]) && (arr[1]<=arr[2]) )
		return 1;
	return 2;
	
}

vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> result;
	result.push_back(array[0]);
	result.push_back(array[1]);
	result.push_back(array[2]);
	
	pair<int,int> min = findMin(result);
	
  for(int i =3; i<array.size(); ++i)
	{
		if(array[i]>min.second)
		{
			result[min.first]=min.second;
			min = findMin(result);
		}
	}
	return result;
	
}


