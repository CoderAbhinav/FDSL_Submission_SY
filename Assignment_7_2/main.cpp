#include <iostream>
#include"Queue.h"
using namespace std;

void printQueue(Queue<int>&);
struct Order
{
    int id;
    int car;
};

int main(){
    Queue<int> q;
    return 0;
}

void printQueue(Queue<int> &q){
    int n = q.size();
    for(int i = 0; i < n; i++){  
        int data = q.front();
        cout<<data<<" ";
        q.dequeue();
        q.enqueue(data);
    }
}