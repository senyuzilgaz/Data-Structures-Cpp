#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  vector<int> result(array.size(),1);
	int product = 1;
	for(int i = 0; i< array.size(); ++i)
	{
		result[i] = product;
		product *= array[i];
	}
	
	product = 1;
	for(int i = array.size()-1; i>=0; --i)
	{
		result[i] *= product;
		product *= array[i];
	}
	
  return result;
}
