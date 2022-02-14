using namespace std;

 This is an input class. Do not edit.
class BinaryTree {
public
  int value;
  BinaryTree left;
  BinaryTree right;

  BinaryTree(int value) {
    this-value = value;
    left = nullptr;
    right = nullptr;
  }
};

pairint,int calcDiameter(BinaryTree node);
int binaryTreeDiameter(BinaryTree tree) {
  pairint,int result = calcDiameter(tree);
	return result.second;
}

 pair height, diameter
pairint,int calcDiameter(BinaryTree node)
{
	if(node == nullptr)
		return{0,0};

	pairint,int resultLeft, resultRight, result;
	resultLeft = calcDiameter(node-left);
	resultRight = calcDiameter(node-right);
	result.first = max(resultLeft.first, resultRight.first)+1;
	result.second = resultLeft.first + resultRight.first;
	result.second = max(max(result.second, resultLeft.second), resultRight.second);
	
	return result;
}

