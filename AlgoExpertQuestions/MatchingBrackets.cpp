using namespace std;
#include<stack>

bool balancedBrackets(string str) {
  unordered_map<char,char> pair = { {'(', ')'}, {'{', '}'}, {'[', ']'} };
  stack<char> sta;
	string opening = "{[(";
	string closing = ")]}";
	for(int i = 0; i < str.size(); ++i)
	{
		if(opening.find(str[i]) != string::npos )
			sta.push(str[i]);
		else if( closing.find(str[i]) != string::npos )
		{
			if( sta.empty() || pair[sta.top()] != str[i])
				return false;
			sta.pop();
		}
	}
	if(!sta.empty())
		return false;
  return true;
}
