#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> ways(n+1, 0);
	ways[0] = 1;
  for(int denom : denoms)
		for( int i = 1; i < n +1 ; ++i)
			if(i >= denom)
				ways[i] += ways[i-denom];
  return ways[n];
}
