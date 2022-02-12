class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  int val = tree->value;
	int temp;
	if(val > target)
	{
		if(tree->left == NULL)
			return val;
		temp = findClosestValueInBst(tree->left, target);
		if(abs(temp-target)>=abs(val-target))
			return val;
		return temp;
	}
	else
	{
		if(tree->right == NULL)
			return val;
		temp = findClosestValueInBst(tree->right, target);
		if(abs(temp-target)>=abs(val-target))
			return val;
		return temp;
	}
	
}
