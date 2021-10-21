#include <iostream>
#include "LinkedList/NodeList.h"
#define deb(x) cout << #x << "=" << x << endl
#define line cout<<"\n"
int main(){
    NodeList l;
    l.insertAtEnd(10);
    l.insertAtBegin(20);
    l.insertAtEnd(30);
    l.deleteNodeAt(2);
    l.printList();
    line;
    cout<<l[2];
    return 0;
}