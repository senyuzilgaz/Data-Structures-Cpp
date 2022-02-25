using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  LinkedList *currentNode, *nextNode;
	currentNode = head;
	nextNode = currentNode -> next;
	while( nextNode != nullptr )
	{
		LinkedList *temp = nextNode;
		nextNode = nextNode -> next;
		temp -> next = currentNode;
		currentNode = temp;
	}
	head -> next = nullptr;
	return currentNode;
}
