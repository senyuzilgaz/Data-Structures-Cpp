using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
 LinkedList *traverse=linkedList, *t2;
	while(traverse!=NULL)
	{
		t2=traverse->next;
		while(t2!=nullptr && t2->value==traverse->value)
		{
			t2=t2->next;
		}
		traverse->next=t2;
		traverse = traverse->next;
	}
	
  return linkedList;
}
