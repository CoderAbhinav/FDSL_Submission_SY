#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* next = NULL;
    Node(T data){
        this->data = data;
    }
};


template <typename T>
class LinkedList
{
private:
    /* data */
    Node<T> *head = NULL;
    Node<T> *tail = NULL;    
    int length = 0;
public:
    LinkedList();
    ~LinkedList();
    void addFirst(T data);
    void addLast(T data);
    void removeFirst();
    void removeLast();
    T First();
    T Last();
    bool isEmpy();
    int size();
    void reverse();
    void print();
};

template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
}

template <typename T>
void LinkedList<T>::addFirst(T data){
    this->length++;
    if(this->head == NULL){
        this->head = new Node<T>(data);
        this->tail = this->head;
        return;
    }
    else{
        Node<T> *toAdd = new Node<T>(data);
        toAdd->next = head;
        this->head = toAdd;
        return;
    }
}

template <typename T>
void LinkedList<T>::addLast(T data){
    this->length++;
    if(this->tail == NULL){
        this->tail = new Node<T>(data);
        this->head = this->tail;
        return;
    }
    else{
        this->tail->next = new Node<T>(data);
        this->tail = this->tail->next;
        return;
    }
}

template <typename T>
void LinkedList<T>::removeFirst(){
    if(this->length == 0){
        throw std::invalid_argument("\nListEmptyException::Try adding some more elements\n");
        return;
    }
    this->length--;
    Node<T> *toDelete = this->head;
    this->head = this->head->next;
    delete toDelete;
    return;
}

template <typename T>
void LinkedList<T>::removeLast(){
    if(this->length == 0){
        throw std::invalid_argument("\nListEmptyException::Try adding some more elements\n");
        return;
    }else if(this->length == 1){
        this->length = 0;
        this->head = NULL;
        this->tail = NULL;
        return;
    }else{
        this->length--;
        Node<T> *toDelete = this->tail;
        Node<T> *temp = this->head;
        while (temp->next->next != NULL)    
        {
            temp = temp->next;
        }
        temp->next = NULL;
        this->tail = temp;
        delete toDelete;     
        return;           
    }
}

template <typename T>
bool LinkedList<T>::isEmpy(){
    return (this->length == 0);
}


template <typename T>
int LinkedList<T>::size(){
    return this->length;
}

template <typename T>
void LinkedList<T>::reverse(){
    if(this->length == 0){
        throw std::invalid_argument("\nListEmptyException::Try adding some more elements\n");
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
void LinkedList<T>::print(){
    Node<T> *temp = this->head;
    cout<<"\n";
    while (temp != NULL)
    {
        cout<<temp->data<<" "<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

template <typename T>
T LinkedList<T>::First(){
    if(this->length == 0){
        throw std::invalid_argument("\nListEmptyException::Try adding some more elements\n");
    }
    return (this->head->data);
}

template <typename T>
T LinkedList<T>::Last(){
    if(this->length == 0){
        throw std::invalid_argument("\nListEmptyException::Try adding some more elements\n");
    }
    return (this->tail->data);
}