#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
	int min;
	int min_ind;
  for(int i=0; i<array.size(); ++i)
	{
		min=INT_MAX;
		for(int j=i+1;j<array.size();++j)
		{
			if(array[j]<min)
			{
				min=array[j];
				min_ind=j;
			}				
		}
		if(min<array[i])
		{
			array[min_ind]=array[i];
			array[i]=min;
		}
	}
  return array;
}
