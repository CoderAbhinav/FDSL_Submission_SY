#include <iostream>
#include "node.h"
using namespace std;

class stack
{
private:
    /* data */
    node* head;
    node* tail;
    int size;

public:
    stack();
    ~stack();
    void push(int);
    void pop();
    int top();
    bool isEmpty();
    int currentSize();
};

stack::stack()
{
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

stack::~stack()
{
}

void stack::push(int data){
    if(this->head == NULL){
        this->head = new node;
        this->tail = this->head;
        this->head->data = data;
        this->size++;
        return;
    }

    node* temp = new node;
    temp->data = data;
    temp->next = this->head;
    this->head = temp;
    size++;
}

void stack::pop(){
    // if head is null then returns
    if(this->head == NULL){
        cout<<"\nWARN : STACK UNDERFLOW";
        return;
    }
    // changing head to next node
    // node* toDelete = this->head;
    this->head = this->head->next;
    // delete toDelete;
    size--;
}

int stack::top(){
    // if the list is empty then return -1
    if(this->head == NULL){
        cout<<"\nWARN : STACK UNDERFLOW";
        return -1;
    }
    
    int rev = this->head->data;
    return rev;
}

bool stack::isEmpty(){
    return (this->size == 0);
}

int stack::currentSize(){
    return (this->size);
}