using namespace std;

int firstNonRepeatingCharacter(string string) {
  unordered_set<char> letters;
	int i;
	for(i =0; i<string.size(); ++i)
	{
		letters.insert(string[i]);
	}
 i=0;
	
	while(i<string.size())
	{
		if(letters.count(string[i])==1)
			return i;
		++i;
	}

	  
  return -1;
}
