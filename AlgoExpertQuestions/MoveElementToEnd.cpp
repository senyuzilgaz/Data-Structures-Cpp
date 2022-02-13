#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  int end = array.size()-1;
	for(int start =0; start < end ; ++start)
	{
		if(array[start] != toMove)
			continue;
		else if( array[start] == toMove)
		{
			if(array[end] != toMove)
				swap(array[start], array[end]);
			else
			{
				while(array[end] == toMove && end>start)
					--end;
			  swap(array[start], array[end]);
			}
			--end;
		}
	}
  return array;
}
