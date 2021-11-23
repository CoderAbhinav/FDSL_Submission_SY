#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    LinkedList<int> l;
    l.addFirst(10);
    // l.addLast(20);
    // l.addLast(30);
    // l.addFirst(-10);

    l.print();
    l.reverse();
    l.print();
    return 0;
}