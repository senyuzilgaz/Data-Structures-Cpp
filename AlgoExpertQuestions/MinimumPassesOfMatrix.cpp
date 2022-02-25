#include <vector>
using namespace std;

void convertNegativeNeighborsToPositive( deque<pair<int,int>> &stack, int row, int column, 
																	vector<vector<int>> &matrix);

int minimumPassesOfMatrix(vector<vector<int>> matrix) {
	int rowLen = matrix.size();
	int columnLen = matrix[0].size();
	int passes = 0;
	bool flag = false;
	deque<pair<int,int>> stack;
  for(int row = 0; row < rowLen; ++row)
		for(int column = 0; column < columnLen; ++column)
			if(matrix[row][column] > 0)
				stack.push_back({row, column});
	stack.push_back({-1, -1});
	
	while(!stack.empty())
	{
		int row = stack.front().first;
		int column = stack.front().second;
		stack.pop_front();
		if(row == -1)
		{
			if(stack.empty())
				break;
			passes += 1;
			stack.push_back({-1,-1});
			continue;
		}
	  convertNegativeNeighborsToPositive(stack, row, column, matrix);
	}
	
	if(containsNegative(matrix))
		return -1;
	
  return passes;
}

void convertNegativeNeighborsToPositive( deque<pair<int,int>> &stack, int row, int column, 
																	vector<vector<int>> &matrix)
{
	int rowSize = matrix.size();
	int colSize = matrix[0].size();
	if( row < rowSize-1 ) //DOWN
		if(matrix[row+1][column] < 0)
		{
			matrix[row+1][column] *= -1;
			stack.push_back( {row+1, column} );
		}
	
	if( row > 0 ) //UP
		if(matrix[row-1][column] < 0)
		{
			matrix[row-1][column] *= -1;
			stack.push_back( {row-1, column});
		}
	
	if( column < colSize-1 ) //RIGHT
		if(matrix[row][column+1] < 0)
		{
			matrix[row][column+1] *= -1;
			stack.push_back( {row, column+1} );
		}
	
	if( column > 0 ) //LEFT
		if(matrix[row][column-1] < 0)
		{
			matrix[row][column-1] *= -1;
			stack.push_back( {row, column-1} );
		}
}

bool containsNegative(vector<vector<int>> &matrix)
{
	for( auto row : matrix)
		for( auto entry : row)
			if( entry < 0 )
				return true;
	return false;
}






