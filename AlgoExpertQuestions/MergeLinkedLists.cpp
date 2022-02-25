#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *mergeLinkedLists(LinkedList *list1, LinkedList *list2)
{
  LinkedList *node1 = list1, *node2 = list2, *prev = nullptr;
  
  while(node1 != nullptr && node2 != nullptr) {
    if(node1 -> value < node2 -> value){
      prev = node1;
      node1 = node1 -> next;
    }else{
      if(prev != nullptr)
        prev -> next = node2;
      prev = node2;
      node2 = node2 -> next;
      prev -> next = node1;
    }
  }
  
  if(node1 == nullptr)
    prev -> next = node2;
   
  if(list1-> value < list2 -> value)
    return list1;
  return list2;
}
