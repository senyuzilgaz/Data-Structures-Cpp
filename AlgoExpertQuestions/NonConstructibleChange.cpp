#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  int currentNonConstructible = 1;
	sort(coins.begin(), coins.end());
	for( int coin : coins){
		if(coin > currentNonConstructible)
			return currentNonConstructible;
		currentNonConstructible += coin;
	}
  return currentNonConstructible;
}
