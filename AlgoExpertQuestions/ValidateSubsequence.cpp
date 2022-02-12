using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int arr_len = array.size(), seq_len = sequence.size();
	int j =0;
	
	for(int i=0; (i<arr_len) && (j<seq_len); ++i)
	{
		if(array[i] == sequence[j])
			++j;
	}
	
	if(j==seq_len)
		return true;
	
	return false;
}
