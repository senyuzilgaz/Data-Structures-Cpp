using namespace std;
int getIndex(int idx, int jump, int len){
  int indx = (idx + jump) % len;
  if(indx < 0)
    indx += len;
  return indx;
}
bool hasSingleCycle(vector<int> arr) {
  int len = arr.size();
  int count = 0;
  int index = 0;
  while(count < len){
    if(count != 0 && index == 0)
      break;
    index = getIndex( index, arr[index], len);
    count++;
  }
	if(index != 0)
		return false;
  return count == len;
}
