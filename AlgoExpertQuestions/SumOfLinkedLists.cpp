using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
  LinkedList * nodeOne = linkedListOne, *nodeTwo = linkedListTwo;
	int carry = 0, sum = 0;
	LinkedList *result = new LinkedList(0);
	LinkedList  *current = result;
	while(nodeOne != nullptr || nodeTwo != nullptr || carry != 0)
	{
		int val1 = nodeOne != nullptr ? nodeOne->value: 0;
		int val2 = nodeTwo != nullptr ? nodeTwo->value: 0;
		sum = val1 + val2 + carry;
	    carry = sum / 10;
		sum = sum % 10;
		LinkedList *newNode = new LinkedList(sum);
		current -> next = newNode;
		current = current -> next;
		nodeOne = nodeOne != nullptr ? nodeOne -> next: nullptr;
		nodeTwo = nodeTwo != nullptr ? nodeTwo -> next: nullptr;
	}
	
  return result -> next;
}