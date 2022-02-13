using namespace std;
int levenshteinDistance(string str1, string str2) {
	vector<int> evenRow(str1.size()+1,0);
	vector<int> oddRow(str1.size()+1,0);
	vector<int> *prevRow, *curRow;
	int minval;
	int len1 = str1.size();
	int len2 = str2.size();
	
	for(int i = 0; i< str1.length()+1; ++i)
	{
		evenRow[i]=i;
	}
	
	for(int i =1; i< len2+1; ++i)
	{
		if(i%2==1)
		{
			curRow= &oddRow;
			prevRow= &evenRow;
		}else{
			curRow= &evenRow;
			prevRow= &oddRow;
		}
		(*curRow)[0]=i;
		for(int j =1; j< len1+1; ++j){
			
			minval= min (min((*curRow)[j-1], (*prevRow)[j-1]), (*prevRow)[j]);
			if(str1[j-1]==str2[i-1])
				(*curRow)[j]= (*prevRow)[j-1];
			else
				(*curRow)[j] = 1+minval;
			
		}		
	}

	return (*curRow)[len1];
	
}