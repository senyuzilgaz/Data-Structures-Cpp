#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> array) {
	int len = array.size();
  vector<int> stack;
	vector<int> result(len, -1);
	int idx = 0;
	for(int i = 0; i < 2*len; ++i)
	{
		idx = i % len;
		while(!stack.empty()){
			int index = stack.back();
			if(array[idx] <= array[index])
			{
				break;
			}else{
				result[index] = array[idx];
				stack.pop_back();
			}
		}
		stack.push_back(idx);
	}
  return result;
}
