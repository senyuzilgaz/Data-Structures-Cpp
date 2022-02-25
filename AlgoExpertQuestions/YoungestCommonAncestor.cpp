#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};
void getHeight(AncestralTree *node, int &height);
AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
  int heightOne = 0, heightTwo = 0;
	getHeight(descendantOne, heightOne);
	getHeight(descendantTwo, heightTwo);
	while(descendantOne != nullptr && descendantTwo != nullptr)
	{
		if(heightOne == heightTwo)
		{
			if(descendantOne == descendantTwo)
				return descendantOne;
			descendantOne = descendantOne -> ancestor;
			heightOne--;
		}
		if(heightOne > heightTwo){
			descendantOne = descendantOne -> ancestor;
			heightOne--;
		}
		else{
			descendantTwo = descendantTwo -> ancestor;
			heightTwo--;
		}
	}
	
  return nullptr;
}

void getHeight(AncestralTree *node, int &height){
	AncestralTree *currentNode = node;
	while(currentNode != nullptr){
		++height;
		currentNode = currentNode -> ancestor;
	}
}
