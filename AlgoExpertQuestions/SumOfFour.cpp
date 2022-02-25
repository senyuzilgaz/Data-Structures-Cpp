#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  sort(array.begin(), array.end());
	int first, second, left, right;
	int len = array.size();
	vector<vector<int>> result;
	
	for(first = 0; first < len-3 ; ++first)
	{
		int firstVal = array[first];
		for(second = first + 1; second < len-2; ++second)
		{
			left = second + 1;
			right = len - 1;
			int secondVal = array[second];
			while(left < right)
			{
				int leftVal = array[left];
				int rightVal = array[right];
				int sumOfFour = firstVal + secondVal + leftVal + rightVal;
				if(sumOfFour == targetSum)
				{
					result.push_back( {firstVal, secondVal, leftVal, rightVal} );
					left++;
				}
				else if(sumOfFour < targetSum)
					left++;
				else
					right--;
			}
		}
	}
  return result;
}
