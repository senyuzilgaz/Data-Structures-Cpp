#include <vector>
using namespace std;
int Hash(string str);
vector<vector<string>> groupAnagrams(vector<string> words) {
	unordered_map<int,vector<string>> umap;
	unordered_map<int,bool> visited;
	int hash;
	vector<vector<string>> result;
	
	for( string str : words)
	{
		hash = Hash(str);
		umap[hash].push_back(str);
		visited[hash] = true;
		
	}
	for( string str : words)
	{
		hash = Hash(str);
		vector<string> res = umap[hash];
		if(visited[hash] == false)
			continue;
		result.push_back(res);
		visited[hash] = false;
	}
  return result;
}

int Hash(string str)
{
	sort(str.begin(), str.end());
	long hash = 0;
	int count;
	for( char ch : str){
		hash += ch*count*count*count;
		++count;
	}
	return hash;
}
