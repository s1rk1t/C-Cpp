//File name: /home/profs/tyi/Courses/2720CPP/dList/node.cpp


class node {
    public:
        node(int val);
	node();
        int data;
        node *prev, *next;
};

node::node(){
}

node::node(int val) {
    data = val;
    prev = next = 0;
}
