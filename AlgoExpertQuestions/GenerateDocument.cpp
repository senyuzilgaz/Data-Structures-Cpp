using namespace std;

bool generateDocument(string characters, string document) {
  unordered_map<char,int> chars;	
	for(auto c : characters)
	{
		chars[c]++;
	}
	for(auto c : document)
	{
		chars[c]--;
		if(chars[c]<0)
			return false;
	}
	
  return true;
}
