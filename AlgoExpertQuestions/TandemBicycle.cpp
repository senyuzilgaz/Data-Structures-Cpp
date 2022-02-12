#include <vector>
using namespace std;

int tandemBicycle(vector<int> red, vector<int> blue,
                  bool fastest) {
	int totalSpeed = 0, r, b;
	bool flag;
  sort(red.begin(), red.end());
	sort(blue.begin(), blue.end());
	if(fastest)
	{
		r=red.size()-1;
		b=r;
		for(int i=0; i < red.size();++i )
		{
			if(red[r]>=blue[b])
				totalSpeed+=red[r--];
			else
				totalSpeed+=blue[b--];
		}
	}
	else
		for(int i = 0; i<red.size();++i)
		{
			if(red[i]>=blue[i])
				totalSpeed+=red[i];
			else
				totalSpeed+=blue[i];	
		}
	return totalSpeed;
  
}
