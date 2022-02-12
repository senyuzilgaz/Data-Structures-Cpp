using namespace std;

bool isPalindrome(string str) {
  int head=0, back=str.size()-1;
	while(head<=back)
	{
		if(str[head]!=str[back])
			return false;
		++head;
		--back;
	}
  return true;
}
