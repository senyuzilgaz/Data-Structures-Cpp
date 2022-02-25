#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  vector<int> memoize(n+1, INT_MAX);
	memoize[0] = 0;
	sort(denoms.begin(), denoms.end());
	for( int denom : denoms)
	{
		for( int i = 1; i <= n; ++i)
		{
			if(denom > i)
				continue;
			if( memoize[i-denom] == INT_MAX)
				continue;
			memoize[i] = min(memoize[i], 1+memoize[i-denom]);
		}
	}
	if(memoize[n] == INT_MAX)
		return -1;
  return memoize[n];
}
