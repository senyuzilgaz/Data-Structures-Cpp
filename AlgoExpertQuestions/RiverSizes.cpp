#include <vector>
using namespace std;

vector<vector<int>> getUnvisitedNeighbors(int i, int j,vector<vector<int>> &matrix,
																												vector<vector<int>> &visited)
{
	
	vector<vector<int>> neighbors{};
	
	if( i > 0 && !visited[i-1][j] )
		neighbors.push_back( {i-1, j} );
	
	if( i < matrix.size()-1 && !visited[i+1][j] )
		neighbors.push_back( {i+1, j} );
	
	if( j > 0 && !visited[i][j-1] )
		neighbors.push_back( {i, j-1} );
	
	if( j< matrix[0].size()-1 && !visited[i][j+1] )
		neighbors.push_back( {i, j+1} );
	
	return neighbors;
}

void traverse(int i, int j, vector<vector<int>> &matrix, 
							vector<vector<int>> &visited, vector<int> &sizes)
{
		int currentRiverSize = 0;
	vector<vector<int>> explore = {{i, j}};
	while(explore.size() != 0)
	{
		vector<int> currentNode = explore.back();
		explore.pop_back();
		i = currentNode[0];
		j = currentNode[1];
		if(visited[i][j])
			continue;
		visited[i][j]=true;
		if(matrix[i][j] == 0)
			continue;
		currentRiverSize++;
		vector<vector<int>> neighbors = getUnvisitedNeighbors(i, j, matrix, visited);
		for(vector<int> v : neighbors)
			explore.push_back(v);
	}
	if(currentRiverSize > 0)
		sizes.push_back(currentRiverSize);
}

vector<int> riverSizes(vector<vector<int>> matrix) {
	vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), false));
	vector<int> sizes = {};
  for(int i = 0; i<matrix.size(); ++i)
	{
		for(int j = 0; j<matrix[0].size(); ++j){
			if(visited[i][j])
				continue;
			traverse(i, j, matrix, visited, sizes);
		}
	}
  return sizes;
}






