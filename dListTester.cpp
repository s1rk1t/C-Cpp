//File name: /home/profs/tyi/Courses/2720CPP/dList/dListTester.cpp
#include "dList.cpp"
#include <iostream>
using namespace std;

//Sample output:
/*
After push_front with 1, 2, 3, the list looks like...
3 2 1 
After the removal of 3, the list looks like...
2 1 
After the removal of 1, the list looks like...
2 
The list has no node with value 4
After the removal of 4, the list looks like...
2 
After the removal of 2, the list looks like...
This is an empty list.

After push_back with 1, 2, 3, the list looks like...
1 2 3 
After the removal of 2, the list looks like...
1 3 
After trying to insert 6 to 2th position, the list looks like...
1 6 3 
After trying to insert 5 to 1th position, the list looks like...
5 1 6 3 
After trying to insert 12 to 4th position, the list looks like...
5 1 6 12 3 
After trying to insert 8 to 6th position, the list looks like...
5 1 6 12 3 8 
After the removal of 3, the list looks like...
5 1 6 12 8 
After trying to insert 16 to 6th position, the list looks like...
5 1 6 12 8 16 
terminate called after throwing an instance of 'std::logic_error'
  what():  The list has 6 elements, you cannot insert element to be in 8th position
*/

int main(int argc, char *argv[]) {
    dList list;
	
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    cout << "After push_front with 1, 2, 3, the list looks like..." << endl;
    list.print();
    int n = 3;
    list.remove(n);
    cout << "After the removal of " << n << ", the list looks like..." << endl; 
    list.print();

    n = 1;
    list.remove(n);
    cout << "After the removal of " << n << ", the list looks like..." << endl; 
    list.print();

    n = 4;
    list.remove(n);
    cout << "After the removal of " << n << ", the list looks like..." << endl; 
    list.print();

    n = 2;
    list.remove(n);
    cout << "After the removal of " << n << ", the list looks like..." << endl; 
    list.print();

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    cout << "After push_back with 1, 2, 3, the list looks like..." << endl;
    list.print();

    n = 2;
    list.remove(n);
    cout << "After the removal of " << n << ", the list looks like..." << endl; 
    list.print();

    int position = 2;
    n = 6;
    list.insert(position, n);
    cout << "After trying to insert " << n << " to " << position << "th position, the list looks like..." << endl; 
    list.print();
 
    position = 1;
    n = 5;
    list.insert(position, n);
    cout << "After trying to insert " << n << " to " << position << "th position, the list looks like..." << endl; 
    list.print();

    position = 4;
    n = 12;
    list.insert(position, n);
    cout << "After trying to insert " << n << " to " << position << "th position, the list looks like..." << endl; 
    list.print();

    position = 6;
    n = 8;
    list.insert(position, n);
    cout << "After trying to insert " << n << " to " << position << "th position, the list looks like..." << endl; 
    list.print();

    n = 3;
    list.remove(n);
    cout << "After the removal of " << n << ", the list looks like..." << endl; 
    list.print();

    position = 6;
    n = 16;
    list.insert(position, n);
    cout << "After trying to insert " << n << " to " << position << "th position, the list looks like..." << endl; 
    list.print();

    position = 8;
    n = 10;
    list.insert(position, n);
    cout << "After trying to insert " << n << " to " << position << "th position, the list looks like..." << endl; 
    list.print();


    return 0;
}
