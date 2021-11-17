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
        throw std::invalid_argument("\nQUEUE OVERFLOW :: The queue is full please dequeue and try again");
        return;
    }

    if(this->end == (this->arr + this->maxSize - 1)){
        this->end = arr;
    }else if(this->queueSize == 0){
        // do nothing
    }else{
        cout<<"END++";
        this->end++;
    }    
    *(this->end) = data;
    this->queueSize++;
}

template <typename T>
void Queue<T>::dequeue(){
    if(queueSize == 0){
        throw std::invalid_argument("\nQUEUE UNDERFLOW :: The queue is empty");
    }
    this->queueSize--;
    if(this->start == (this->arr + this->maxSize - 1)){
        this->start = this->arr;
        return;
    }
    cout<<"START++";
    this->start++;
}

template <typename T>
T Queue<T>::front(){
    return *(this->start);
}

template <typename T>
T Queue<T>::back(){
    return *(this->end);
}

template <typename T>
int Queue<T>::size(){
    return (this->queueSize);
}

template <typename T>
bool Queue<T>::isEmpty(){
    return (this->queueSize == 0);
}