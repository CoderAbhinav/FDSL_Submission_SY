#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T *arr;
    T *start;
    T *end;
    int maxSize;
    int queueSize = 0;

public:
    Queue(int);
    ~Queue();
    void enqueue(T data);
    void dequeue();
    T front();
    T back();
    int size();
    bool isEmpty();
};

template <typename T>
Queue<T>::Queue(int size)
{
    this->maxSize = size;
    this->arr = new int[size];
    this->start = arr;
    this->end = arr;
}


template <typename T>
Queue<T>::~Queue()
{
}

template <typename T>
void Queue<T>::enqueue(T data){
    if(this->queueSize == this->maxSize){
        throw std::invalid_argument("\nQueue::enqueue(T data) | QUEUE OVERFLOW :: The queue is full please dequeue and try again");
        return;
    }

    this->arr[this->queueSize] = data;
    this->queueSize++;
}

template <typename T>
void Queue<T>::dequeue(){
    if(queueSize == 0){
        throw std::invalid_argument("\nQueue::dequeue() | QUEUE UNDERFLOW :: The queue is empty");
    }
    for(int i = 1; i < this->queueSize; i++){
        this->arr[i-1] = this->arr[i];
    }
    this->queueSize--;
}

template <typename T>
T Queue<T>::front(){
    if(queueSize == 0){
        throw std::invalid_argument("\nQueue::front() | QUEUE UNDERFLOW :: The queue is empty");
    }
    return *(this->arr);
}

template <typename T>
T Queue<T>::back(){
    if(queueSize == 0){
        throw std::invalid_argument("\nQueue::back() | QUEUE UNDERFLOW :: The queue is empty");
    }
    return (this->arr[this->queueSize-1]);
}

template <typename T>
int Queue<T>::size(){
    return (this->queueSize);
}

template <typename T>
bool Queue<T>::isEmpty(){
    return (this->queueSize == 0);
}