#pragma once
#include <iostream>
using namespace std;



// node defination with template

struct Node
{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }   
};

// class defination

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList();
    ~LinkedList();
    // insert
    void addFirst(int data);
    void addLast(int data);
    // delete
    void removeFirst();
    void removeLast();
    // access
    int first();
    int last();
    // stats
    bool isEmpty();
    int size();
    // non-native
    friend void reverse(LinkedList);
    friend void printList(LinkedList);
};


LinkedList::LinkedList()
{
    // O(1)
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}


LinkedList::~LinkedList()
{
    // O(n)
    // deleting all linked list nodes
    Node* temp = this->head;
    while(temp != nullptr){
        Node* toDelete = temp;
        temp = temp->next;
    }
}


void LinkedList::addFirst(int data){
    // O(1)
    this->length++;
    // checking if the list is empty
    if(this->head == nullptr){
        this->head = new Node(data);
        this->tail = this->head; // updating tail
    }else{
        Node* toAdd = new Node(data);
        toAdd->next = this->head;
        this->head = toAdd;
    }
}


void LinkedList::addLast(int data){
    // O(1)
    // checking if the list is empty
    if(this->tail == nullptr){
        this->addFirst(data);
    }else{
        this->length++;
        this->tail->next = new Node(data);
        this->tail = this->tail->next; // updating tail
    }
}


void LinkedList::removeFirst(){
    // O(1)
    // checking if the list is empty
    if(head == nullptr){
        throw std::invalid_argument("ListEmptyException");
        return;
    }
    Node* toDelete = this->head;
    this->head = this->head->next; // updating head
    this->length--;
    delete toDelete;
    // checking if head pointer is null and updating tail
    if(this->head == nullptr) this->tail = nullptr;
}


void LinkedList::removeLast(){
    // O(n)
    // checking if list is empty
    if(this->tail == nullptr){
        throw  std::invalid_argument("ListEmptyException");
        return;
    }
    
    this->length--;
    Node* toDelete = this->tail;
    // checking if there is only one node
    if(this->tail == this->head){
        this->head = nullptr;
        this->tail = nullptr;
        delete toDelete;
        return;    
    }
    
    // traversing to one node before tail node
    Node* temp = this->head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    this->tail = temp; // upating tail
    this->tail->next = nullptr;
    delete toDelete;
}

int LinkedList::first(){
    // O(1)
    if(this->head == nullptr){
        throw std::invalid_argument("ListEmptyException");
    }
    return this->head->data;
}


int LinkedList::last(){
    // O(1)
    if(this->head == nullptr){
        throw std::invalid_argument("ListEmptyException");
    }
    return this->tail->data;
}


bool LinkedList::isEmpty(){
    return (this->length == 0);
}


int LinkedList::size(){
    return (this->length);
}


void reverse(LinkedList list){

    // underflow condition check
    if(list.head == nullptr){
        throw std::invalid_argument("ListEmptyException");
    }
    // maintaining three pointers
    Node *temp = list.head;
    Node *prev = NULL;
    Node *nxt;

    // swapping head & tail
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



void printList(LinkedList list){
    Node* temp = list.head;
    while (temp != nullptr) // traversing
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null";
    
}