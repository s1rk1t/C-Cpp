#include"node.cpp"
class dList {
public:
dList();
~dList();
void push_front(int val);
void push_back(int val);
void pop_front();
void pop_back();
int front(); //access the first element
int back(); //access the last element
void insert(int position, const int& val);
//insert a node with val,
//make it as the (position)th element in the list.
//If the position is not valid -- for example,
//insert a node to be 10th node in a list of 8 nodes,
//or position is negative -- throw an exception.
void remove(const int& val);
//remove the node with value val,
//if no node has such value,
//give prompt "no node with value blahblah"
int size();
bool empty();
void print(); //print out the list from head to tail
private:
node *head, *tail;
};
