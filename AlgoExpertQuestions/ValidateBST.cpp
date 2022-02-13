class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};
bool helper(BST *node, int max, int min);
bool validateBst(BST *tree) {
  return helper(tree,INT_MIN,INT_MAX);
}
bool helper(BST *node, int max, int min)
{
	if(node == nullptr)
		return true;
	int val = node-> value;
	if(val >= min || val < max)
		return false;
	return helper(node->left, max, val) && helper(node->right, val, min);
}
