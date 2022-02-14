using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
	int maxHeight = INT_MIN;
	vector<int> result;
  if(direction == "WEST")
		for(int i = 0; i < buildings.size(); ++i)
		{
			int currentHeight = buildings[i];
			if(currentHeight > maxHeight)
			{
				result.push_back(i);
				maxHeight = currentHeight;
			}
		}
	else
	{
		for(int i = buildings.size()-1; i >= 0; --i)
		{
			int currentHeight = buildings[i];
			if(currentHeight > maxHeight)
			{
				result.push_back(i);
				maxHeight = currentHeight;
			}
		}	
		reverse(result.begin(), result.end());
	}

	return result;
}
