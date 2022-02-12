using namespace std;

int getNthFib(int n) {
	int res[] = {0,1};
  if(n==0 || n==1)
	{
		return 0;
	}
	else if(n==2)
	{
		return 1;
	}
	int nextfib=0;
	for(int i = 3; i<=n; ++i)
	{
		nextfib=res[0]+res[1];
		res[0]=res[1];
		res[1]=nextfib;
	}
	return res[1];
}
