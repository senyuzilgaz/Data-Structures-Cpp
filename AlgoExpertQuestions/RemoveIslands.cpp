#include <vector>
using namespace std;
void getNeighbours(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &stack);
void explore(int row, int column, vector<vector<int>> &matrix)
{
	vector<vector<int>> stack = {{row,column}};
	
	while(!stack.empty())
	{
		vector<int> currentNode = stack.back();
		stack.pop_back();
	  int curRow = currentNode[0];
		int curCol = currentNode[1];
		
		matrix[curRow][curCol] = 2;
		
		getNeighbours(curRow, curCol, matrix, stack);
	}
}
vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
	int height = matrix.size();
	int width = matrix[0].size();
  vector<vector<bool>> visited(height+1,vector<bool>(width, false));
	
	for(int row = 0; row < height; ++row)
	{
		bool rowIsBorder = (row == 0) || (row == height-1);
		for(int column = 0; column < width; ++column)
		{
			bool columnIsBorder = (column == 0) || (column == width-1);
			bool isBorder = rowIsBorder || columnIsBorder;
			if(!isBorder || matrix[row][column]!=1)
				continue;
			
			explore(row, column, matrix);	
		}
	}
	
	for(int row = 0; row < height; ++row)
	{
		for(int column = 0; column < width; ++column)
		{
			if(matrix[row][column] == 1)
				matrix[row][column] = 0;
			
			else if(matrix[row][column] == 2)
				matrix[row][column] = 1;
		}
	}
  return matrix;
}
void getNeighbours(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &stack)
{
	int height = matrix.size();
	int width = matrix[0].size();
	if(i>0)
		if(matrix[i-1][j] == 1)
			stack.push_back({i-1, j}); //UP
	if(i < height-1)
		if(matrix[i+1][j] == 1)
			stack.push_back({i+1, j}); //DOWN
	if(j>0)
		if(matrix[i][j-1] == 1)
			stack.push_back({i, j-1});//LEFT
	if(j < width-1)
		if(matrix[i][j+1] == 1)
			stack.push_back({i, j+1}); //RIGHT
}
