
#include <vector>
using namespace std;

vector<int> sortKSortedArray(vector<int> array, int k) {
  priority_queue <int, vector<int>, greater<int>> minHeap ;
  int len = array.size();
  int sortedIndex = 0;
  
  for(int i = 0; i < len && i <= k; ++i)
    minHeap.push(array[i]);
  
  for(unsigned int i = k + 1; i < array.size(); ++i)
  {
    array[sortedIndex++] = minHeap.top();
    minHeap.pop();
    minHeap.push(array[i]);
  }
  while(!minHeap.empty())
  {
    array[sortedIndex++] = minHeap.top();
    minHeap.pop();
  }
  
  return array;
}
