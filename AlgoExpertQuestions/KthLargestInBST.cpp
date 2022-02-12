using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void inOrderTraverse(BST *root, vector<int> &arr)
{
	if(root == nullptr)
		return;
	
	inOrderTraverse(root->left, arr);
	arr.push_back(root->value);
	inOrderTraverse(root->right, arr);
}
int findKthLargestValueInBst(BST *tree, int k) {
  vector<int> result;
	inOrderTraverse(tree, result);
	return result[result.size()-k];
}
