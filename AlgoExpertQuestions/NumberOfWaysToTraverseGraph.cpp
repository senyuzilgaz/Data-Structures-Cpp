using namespace std;
int factorial(int n);
int numberOfWaysToTraverseGraph(int width, int height) {
  return factorial(width + height -2)/( factorial(width-1) * factorial(height-1) );
  return -1;
}

int factorial(int n){
	long sum = 1;
	for(int i = 2; i <= n; ++i)
		sum *= i;
	return sum;
}
