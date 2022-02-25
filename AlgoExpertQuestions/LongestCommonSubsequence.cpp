#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
	int len1 = str1.size();
	int len2 = str2.size();
  vector<vector<int>> table(len1 + 1, vector<int>(len2+1, 0));
	vector<char> result;
	for( int row = 1; row < len1 + 1; ++row){
		for( int col = 1; col < len2 + 1; ++col){
			if(str1[row-1] == str2[col-1]){
				table[row][col] =	table[row-1][col-1]+1;
			}
			else{
				table[row][col] = max(table[row-1][col], table[row][col-1]);
			}
		}
	}
	int i = len1, j = len2;
	while(i >= 1 && j >= 1 && table[i][j] != 0)
	{
		while(table[i][j] == table[i][j-1])
			--j;
		while(table[i][j] == table[i-1][j])
			--i;
		if(table[i][j] != 0)
			result.push_back(str2[j-1]);
		--i;
		--j;
		
	}
	cout << table[len1][len2];
	reverse(result.begin(), result.end());
  return result;
}
