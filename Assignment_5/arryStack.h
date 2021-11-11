#include <iostream>
using namespace std;

class Stack{
    private:
    int* stackArray;
    int* topPointer;
    int size;
    int elementCount = 0;
    
    public:
    Stack(int);

    void push(int);
    void pop();
    int top();
    bool isEmpty();
    int currentSize();
    int sizeOfStack();
};

Stack::Stack(int size){
    this->size = size;
    // allocating memory to array
    this->stackArray = new int[size];
    // setting topPointer to zeroth element of array
    topPointer = stackArray;
}

void Stack::push(int data){
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

int Stack::top(){
    return *(this->topPointer);
}

void Stack::pop(){
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

bool Stack::isEmpty(){
    // checking if stack is empty
    return (this->elementCount == 0);
}

int Stack::currentSize(){
    // returning the size of stack
    return (this->elementCount);
}

int Stack::sizeOfStack(){
    return (this->size);
}