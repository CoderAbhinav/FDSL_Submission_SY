#pragma once
#include <iostream>
using namespace std;

// declaration of class and friend function
template <typename T> struct Node;
template <typename T> class LinkedList;
template <typename T> void printList(LinkedList<T>);
template <typename T> void reverse(LinkedList<T>);

// node defination with template
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

// class defination
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


    bool isEmpty();
    int size();

    friend void reverse<>(LinkedList);
    friend void printList<>(LinkedList);
};

template <typename T>
LinkedList<T>::LinkedList()
{
    // O(1)
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    // O(n)
    // deleting all linked list nodes
    Node<T>* temp = this->head;
    while(temp != nullptr){
        Node<T>* toDelete = temp;
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::addFirst(T data){
    // O(1)
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
    // O(1)
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
    // O(1)
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
    // O(n)
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
    // O(1)
    if(this->head == nullptr){
        throw std::invalid_argument("ListEmptyException");
    }
    return this->head->data;
}

template <typename T>
T LinkedList<T>::last(){
    // O(1)
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
void reverse(LinkedList<T> list){
    // O(1)
    if(list.head == nullptr){
        throw std::invalid_argument("ListEmptyException");
    }
    // maintaining three pointers
    Node<T> *temp = list.head;
    Node<T> *prev = NULL;
    Node<T> *nxt;
    // swapping head and tail
    list.head = list.tail;
    list.tail = temp;
    // traversing and updating
    while(temp != NULL){
        nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
}


template <typename T>
void printList(LinkedList<T> list){
    Node<T>* temp = list.head;
    while (temp != nullptr) // traversing
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null";
}