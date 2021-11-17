#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
    Queue<int> q(5);
    q.enqueue(10);
    cout<<q.front();
    q.dequeue();
    q.enqueue(20);
    cout<<q.front();
    return 0;
}