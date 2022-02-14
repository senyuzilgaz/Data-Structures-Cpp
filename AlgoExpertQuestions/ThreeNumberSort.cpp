#include <vector>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  int first = order[0];
	int second = order[1];
	int firstIndex = 0;
	int secondIndex = 0;
	int thirdIndex = array.size()-1;
	
	while(secondIndex <= thirdIndex)
	{
		if(array[secondIndex] == first)
		{
			swap(array[firstIndex], array[secondIndex]);
			++firstIndex;
			++secondIndex;
		}
		else if ( array[secondIndex] == second)
			++secondIndex;
		else{
			swap(array[secondIndex], array[thirdIndex]);
			--thirdIndex;
		}
	}
  return array;
}
