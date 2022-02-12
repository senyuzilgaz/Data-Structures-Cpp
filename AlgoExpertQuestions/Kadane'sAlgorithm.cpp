#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  int maxx = array[0];
	int prevMax = array[0];
	int current;
	for(int i = 1; i < array.size(); ++i)
	{
		current = array[i];
		prevMax = max(current, prevMax+current);
		maxx = max(maxx, prevMax);
	}
  return maxx;
}
