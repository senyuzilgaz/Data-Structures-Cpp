#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> arr) {
	int key=0,k;
  for(int i=1; i<arr.size(); ++i)
	{
		key = arr[i];
		k=i-1;
		while( (k>=0) && (arr[k]>key))
		{
			arr[k+1]=arr[k];
			k-=1;
		}
		arr[k+1]=key;
	}
  return arr;
}
