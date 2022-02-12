#include <vector>
using namespace std;

bool classPhotos(vector<int> red, vector<int> blue) {
	
  sort(red.begin(), red.end());
	sort(blue.begin(), blue.end());
		
	if(red[0]<=blue[0])
		for(int i=0; i<red.size(); ++i)
			if(red[i]>=blue[i])
				return false;
	
	else if(red[0]>=blue[0])
		for(int i=0; i<red.size(); ++i)
			if(red[i]<=blue[i])
				return false;
	
  return true;
}
