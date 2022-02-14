#include <vector>
using namespace std;
int getIndex(unordered_map<int,vector<int>> &umap, int duration);
vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
	vector<vector<int>> result;
	vector<int> sortedTasks = tasks;
	unordered_map<int,vector<int>> umap;
  sort(sortedTasks.begin(), sortedTasks.end());
	
	for(int i = 0; i< tasks.size(); ++i){
		umap[tasks[i]].push_back(i);
	}
	
	int second = sortedTasks.size()-1;
	int first = 0;
	while(first < second)
	{
		int firstIndex, secondIndex;
		firstIndex= getIndex(umap, sortedTasks[first]);
		secondIndex= getIndex(umap, sortedTasks[second]);
		result.push_back({firstIndex,secondIndex});
		++first;
		--second;
	}
  return result;
}
int getIndex(unordered_map<int,vector<int>> &umap, int duration){
	int index;
	if(umap.find(duration) != umap.end())
	{
		index = umap[duration].back();
		umap[duration].pop_back();
	}
	return index;
}




