using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};
pair<int,bool> isBalanced( BinaryTree *node);

bool heightBalancedBinaryTree(BinaryTree *tree) {
  return isBalanced(tree).second;
}

pair<int,bool> isBalanced( BinaryTree *node){
	pair<int, bool> resultLeft, resultRight, result;
	if(node == nullptr)
		return {0, true};
	resultLeft = isBalanced(node->left);
	resultRight = isBalanced(node->right);
	result.first = max(resultLeft.first, resultRight.first)+1;
	result.second = resultLeft.second && resultRight.second;
	if( abs(resultLeft.first - resultRight.first) > 1 )
		result.second = false;
	return result;
}


