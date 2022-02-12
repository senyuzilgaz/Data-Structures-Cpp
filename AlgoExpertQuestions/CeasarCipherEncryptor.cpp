using namespace std;

string caesarCypherEncryptor(string str, int key) {
  
	for( int i =0; i<str.size(); ++i)
		str[i] = 'a'+ ((str[i]+key-'a')%26);
	
	return str;
}

