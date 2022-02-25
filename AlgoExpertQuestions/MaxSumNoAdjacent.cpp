#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  int len = array.size();
  int first = 0, second = 0;
  if(len == 0)
    return 0;
  
  if(len == 1)
    return array[0];
  
  first = array[0];
  second = max(array[1], array[0]);
  
  for(int i = 2; i < len; ++i){
    int temp = max(first + array[i], second);
    first = second;
    second = temp;
  }
  
  return second;
}
