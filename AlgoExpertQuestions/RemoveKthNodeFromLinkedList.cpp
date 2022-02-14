#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
  LinkedList *currentNode = head, *forwardNode = head, *prevNode;
	int i = 0;
	while(i++ < k)
		forwardNode = forwardNode -> next;
	while(forwardNode != nullptr)
	{
		forwardNode = forwardNode -> next;
		prevNode = currentNode;
		currentNode = currentNode -> next;
	}
	if(head != currentNode)
		prevNode -> next = currentNode -> next;
	else
	{
		head -> value = head->next->value;
		head->next = head -> next -> next;
	}
}

