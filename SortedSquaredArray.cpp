#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
	vector<int> sortedSquares(array.size(), 0);
	int front = 0, back = array.size()-1;
	
	for(int i = array.size()-1; i>=0; --i)
	{
		int smallerValue = array[front];
		int largerValue = array[back];
		
		if(abs(smallerValue)> abs(largerValue))
		{
			sortedSquares[i] = smallerValue*smallerValue;
			++front;
		}
		else
		{
			sortedSquares[i] = largerValue*largerValue;
			--back;
		}
	}
	return sortedSquares;
}
