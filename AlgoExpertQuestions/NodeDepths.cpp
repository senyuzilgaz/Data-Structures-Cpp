using namespace std;



class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int depthCalcHelper(BinaryTree *root, int currentDepth)
{
	if(root == NULL)
		return 0;
	return currentDepth + 
		depthCalcHelper(root->left,currentDepth+1) + 
		depthCalcHelper(root->right,currentDepth+1); 
}

int nodeDepths(BinaryTree *root) {
	if(root == NULL)
		return 0;
	return depthCalcHelper(root->left,1) + depthCalcHelper(root->right,1);
}


	
	
	
	
	