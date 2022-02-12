#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	int len = array.size();
	unordered_set<int> umap;
	vector<int> result;
	for (int i = 0; i < len; ++i)
	{
		if (umap.find(targetSum - array[i]) != umap.end())
		{
			result.push_back(targetSum - array[i]);
			result.push_back(array[i]);
			return result;
		}
		umap.insert(array[i]);
	}
	return {};
}