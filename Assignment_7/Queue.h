#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class Queue
{
private:
    Node<T> *start;
    Node<T> *end;
    int queueSize;
public:
    Queue();
    ~Queue();
    void enqueue(T data);
    void dequeue();
    T front();
    T back();
    int size();
    bool isEmpty();
};

template <typename T>
Queue<T>::Queue()
{
    queueSize = 0;
    start = NULL;
    end = NULL;
}

template <typename T>
Queue<T>::~Queue()
{
}

template <typename T>
void Queue<T>::enqueue(T data){
    this->queueSize++;
    if(this->end == NULL){
        this->end = new Node<T>(data);
        this->start = this->end;
        this->end = this->start;
        return;
    }

    Node<T> *toAdd = new Node<T>(data);
    toAdd->next = this->start;
    this->end->next = toAdd;
    this->end = this->end->next;
    return;
}

template <typename T>
void Queue<T>::dequeue(){
    if(this->start == this->end){
        this->start = NULL;
        this->end = NULL;
        this->queueSize--;
        throw std::invalid_argument("\nQUEUE UNDERFLOW :: The queue is already empty; Try Adding some elements");
        return;
    }
    Node<T> *toDelete = this->start;
    this->start = this->start->next;
    this->end->next = this->start;
    delete toDelete;
    this->queueSize--;

}

template <typename T>
T Queue<T>::front(){
    if(this->start == NULL){
        throw std::invalid_argument("\nQUEUE UNDERFLOW :: The queue is already empty; So pointers are null");
    }
    return this->start->data;
}

template <typename T>
T Queue<T>::back(){
    if(this->end == NULL){
        throw std::invalid_argument("\nQUEUE UNDERFLOW :: The queue is already empty; So pointers are null");
    }
    return this->end->data;
}

template <typename T>
bool Queue<T>::isEmpty(){
    return (this->queueSize == 0);
}

template <typename T>
int Queue<T>::size(){
    return (this->queueSize);
}