#pragma once
#include <iostream>
using namespace std;

// declaration of class and friend function
template <typename T> struct Node;
template <typename T> class LinkedList;
template <typename T> void printList(LinkedList<T>);

template <typename T>
struct Node
{
    T data;
    Node* next;
    Node(T data){
        this->data = data;
        this->next = nullptr;
    }   
};


template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:
    LinkedList();
    ~LinkedList();

    void addFirst(T data);
    void addLast(T data);
    
    void removeFirst();
    void removeLast();

    T first();
    T last();

    void reverse();

    bool isEmpty();
    int size();

    friend void printList<>(LinkedList);
};

template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* temp = this->head;
    while(temp != nullptr){
        Node<T>* toDelete = temp;
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::addFirst(T data){
    this->length++;
    // checking if the list is empty
    if(this->head == nullptr){
        this->head = new Node<T>(data);
        this->tail = this->head; // updating tail
    }else{
        Node<T>* toAdd = new Node<T>(data);
        toAdd->next = this->head;
        this->head = toAdd;
    }
}

template <typename T>
void LinkedList<T>::addLast(T data){
    // checking if the list is empty
    if(this->tail == nullptr){
        this->addFirst(data);
    }else{
        this->length++;
        this->tail->next = new Node<T>(data);
        this->tail = this->tail->next; // updating tail
    }
}

template <typename T>
void LinkedList<T>::removeFirst(){
    // checking if the list is empty
    if(head == nullptr){
        throw std::invalid_argument("ListEmptyException");
        return;
    }
    Node<T>* toDelete = this->head;
    this->head = this->head->next; // updating head
    this->length--;
    delete toDelete;
    // checking if head pointer is null and updating tail
    if(this->head == nullptr) this->tail = nullptr;
}

template <typename T>
void LinkedList<T>::removeLast(){
    // checking if list is empty
    if(this->tail == nullptr){
        throw  std::invalid_argument("ListEmptyException");
        return;
    }
    
    this->length--;
    Node<T>* toDelete = this->tail;
    // checking if there is only one node
    if(this->tail == this->head){
        this->head = nullptr;
        this->tail = nullptr;
        delete toDelete;
        return;    
    }
    
    // traversing to one node before tail node
    Node<T>* temp = this->head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    this->tail = temp; // upating tail
    this->tail->next = nullptr;
    delete toDelete;
}

template <typename T>
T LinkedList<T>::first(){
    if(this->head == nullptr){
        throw std::invalid_argument("ListEmptyException");
    }
    return this->head->data;
}

template <typename T>
T LinkedList<T>::last(){
    if(this->head == nullptr){
        throw std::invalid_argument("ListEmptyException");
    }
    return this->tail->data;
}

template <typename T>
bool LinkedList<T>::isEmpty(){
    return (this->length == 0);
}

template <typename T>
int LinkedList<T>::size(){
    return (this->length);
}

template <typename T>
void LinkedList<T>::reverse(){
    if(this->head == nullptr){
        throw std::invalid_argument("ListEmptyException");
    }
    Node<T> *temp = this->head;
    Node<T> *prev = NULL;
    Node<T> *nxt;
    this->head = this->tail;
    this->tail = temp;

    while(temp != NULL){
        nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
}


template <typename T>
void printList(LinkedList<T> l){
    Node<T>* temp = l.head;
    while (temp != nullptr)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null";
    
}