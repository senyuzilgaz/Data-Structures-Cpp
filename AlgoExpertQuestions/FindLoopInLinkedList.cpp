#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
  LinkedList *first = head, *second = head;
	first = first->next;
	second = second -> next -> next;
	while(first!=second){
		first = first -> next;
		second = second->next -> next;
	}
	first = head;
	while(first != second){
		first = first -> next;
		second = second -> next;
	}
	return first;
}
