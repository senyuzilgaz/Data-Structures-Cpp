using namespace std;

// This is the class of the input root. Do not edit it.
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
void calculateBS(BinaryTree *root, int sum, vector<int> &res)
{
	if(root == nullptr)
		return;
	sum += root-> value;
	if(root->left == nullptr && root->right==nullptr)
	{
		res.push_back(sum);
		return;
	}
	
	calculateBS(root->left, sum, res);
	calculateBS(root->right, sum, res);
	return;
		
	
}

vector<int> branchSums(BinaryTree *root) {
  vector<int> res;
	calculateBS(root, 0, res);
	return res;
}








