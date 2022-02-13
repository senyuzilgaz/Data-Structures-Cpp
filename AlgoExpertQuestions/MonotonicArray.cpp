using namespace std;

bool isMonotonic(vector<int> arr) {
  int len = arr.size();
	int flag = 2;
	
	if(len <=1 )
		return true;
	for(int i = 1; i< len; ++i)
	{
		if(arr[i] > arr[i-1]){
			if(flag == 2)
				flag = 1;
			else if(flag == 0)
				return false;
		}else if(arr[i] < arr[i-1]){
			if(flag == 2)
				flag = 0;
			else if(flag == 1)
				return false;
		}
	}
	return true;
}
