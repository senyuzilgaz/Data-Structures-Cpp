#include vector
using namespace std;

int firstDuplicateValue(vectorint array) 
{ 
	for(int i =0; i array.size(); ++i)
	{
		int absv = abs(array[i]);
		if(array[absv-1]0)
			return absv;
		array[absv-1] = -1;
	}
	return -1;
	
	
	
}
