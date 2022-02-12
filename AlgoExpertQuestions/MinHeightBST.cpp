using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};
int calcIndex(int left, int right)
{
	return (left+right)/2;
}
BST *minHeightHelper(int left, int right, vector<int> arr){
	if(left>right)
		return nullptr;
	int indx = calcIndex(left, right);
	BST *tree = new BST(arr[indx]);
	tree -> left = minHeightHelper(left, indx - 1, arr);
	tree -> right = minHeightHelper(indx + 1 , right, arr);
	return tree;
}
BST *minHeightBst(vector<int> array) {
  return minHeightHelper(0, array.size()-1, array);
}



