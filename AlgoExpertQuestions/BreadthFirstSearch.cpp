#include <vector>
using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
		deque<Node> queue = {*this};
		Node current = *this;
		while(!queue.empty())
		{
			current= queue.front();
			queue.pop_front();
			array->push_back(current.name);
			for( auto child : current.children)
			{
				queue.push_back(*child);
			}
		}
		return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
