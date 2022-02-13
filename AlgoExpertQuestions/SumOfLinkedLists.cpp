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
  int sum = 0, mult = 1, x = 0;
	LinkedList *cur = linkedListOne;
	LinkedList *result = new LinkedList(0);
	while(cur != nullptr)
	{
		sum += (cur->value * mult);
		mult *= 10;
		cur = cur->next;
	}
	cur = linkedListTwo;
	mult = 1;
	while(cur != nullptr)
	{
		sum += (cur->value * mult);
		mult *= 10;
		cur = cur->next;
	}
	cur = result;
	mult=10;
	while(sum != 0)
	{
		x = sum % mult;
		sum -= x;
		mult *= 10;
		LinkedList * newNode = new LinkedList( x/(mult/100) );
		cur->next = newNode;
		cur = cur -> next;
	}
	if(result->next != nullptr)
  	return result->next;
	return result;
}