#include <iostream>
using namespace std;

class stack{
    private:
    int* stackArray;
    int* topPointer;
    int size;
    int elementCount = 0;
    
    public:
    stack(int);

    void push(int);
    void pop();
    int top();
    bool isEmpty();
    int currentSize();
    int sizeOfStack();
};

stack::stack(int size){
    this->size = size;
    // allocating memory to array
    this->stackArray = new int[size];
    // setting topPointer to zeroth element of array
    topPointer = stackArray;
}

void stack::push(int data){
    // checking if the stack is full
    if(this->elementCount == this->size){
        cout<<"\nWARNING : STACK OVERFLOW";
        return;
    }
    // if it's empty then allocate to the first position
    if(this->elementCount == 0){
        *(this->topPointer) = data;
        this->elementCount++;
        return;
    }
    this->topPointer++;
    *(this->topPointer) = data;
    this->elementCount++;
    return;
}

int stack::top(){
    return *(this->topPointer);
}

void stack::pop(){
    // checking if the stack is empty
    if(this->elementCount == 0){
        cout<<"\nWARNING : STACK UNDERFLOW";
        return;
    }
    // decrementing the topPointer
    this->topPointer--;
    this->elementCount--;
    return;
}

bool stack::isEmpty(){
    // checking if stack is empty
    return (this->elementCount == 0);
}

int stack::currentSize(){
    // returning the size of stack
    return (this->elementCount);
}

int stack::sizeOfStack(){
    return (this->size);
}