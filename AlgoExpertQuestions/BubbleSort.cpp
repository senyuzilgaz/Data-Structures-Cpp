#include <vector>
using namespace std;
void Swap(int *x, int *y)
{
	int temp = *x;
	*x=*y;
	*y=temp;
}
vector<int> bubbleSort(vector<int> array) {
  for(int i=0; i<array.size();++i)
	{
		for(int j=0; j<array.size()-1;++j)
		{
			if(array[j]>array[j+1])
				Swap(&array[j],&array[j+1]);
		}
	}
  return array;
}
