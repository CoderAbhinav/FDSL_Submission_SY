#include <iostream>
#include "Node.h"
using namespace std;



class NodeList
{
private:
    Node *head;       // track head of list
    Node *tail = NULL; // tracks the end of list
    int size;       // trcks the size of list

public:
    NodeList();
    ~NodeList();
    void printList(); // prints all list elements space separated
    void insertAtBegin(employee data);
    void insertAtEnd(employee data);
    void insertAt(int index, employee data); // index from 0 to n; inserts at given index
    void deleteNodeAt(int index);       // delete node at index from 0 to n
    employee elementAtIndex(int index);
    employee elementAtStart();
    employee elementAtEnd();
    int sizeOfList(); // returns size of list
    
    employee operator[](int); // these are just for getting an int by value
    int find(int key);
};

NodeList::NodeList()
{
    // Worst Case O(1); constant
    this->head = this->tail;
    size = 0;
}

NodeList::~NodeList()
{
}

void NodeList::printList()
{
    // O(size); linear
    Node *temp = this->head; // creating temporary pointer
    while (temp != NULL)
    {

        temp->data.printDetails(); // printing data
        temp = temp->next; // traversing
    }
}

void NodeList::insertAtBegin(employee data)
{
    // O(1); constant
    size++; // incrementing size
    if (this->head == NULL)
    {
        insertAtEnd(data);
        return;
    }
    Node *temp = new Node; // allocating memory
    temp->data = data;
    temp->next = head; // linking old head to the new head
    this->head = temp; // updating head
}

void NodeList::insertAtEnd(employee data)
{
    // O(1); constant
    size++;          // incrementing size
    if (tail == NULL) // if the list is not initialized or the head == end == NULL
    {
        tail = new Node; // allocating memory
        head = tail;
        tail->data = data;
    }
    else
    {
        tail->next = new Node; // allocating memory to the next of end
        tail = tail->next;
        tail->data = data;
    }
}

void NodeList::insertAt(int index, employee data)
{

    // O(index); linear
    // checks if the index is not greater than last index
    if (index > size)
    {
        cout << "\n!!!Index is out of range!!!\n";
        return;
    }

    size++; // incrementing size
    Node *temp = this->head;

    Node *toAdd = new Node; // creating node to be added
    toAdd->data = data;

    // if to be added at begining then
    if (index == 0)
    {
        toAdd->next = temp;
        this->head = toAdd;
        return;
    }

    // iterating upto the previous node of the target position
    index--;
    while (index--)
    {
        temp = temp->next;
    }

    toAdd->next = temp->next; // connecting to index+1 node
    temp->next = toAdd;       // connecting previous node to new node
    // if the new node added at end then we will update the end pointer
    if (toAdd->next == NULL)
    {
        tail = toAdd;
    }
}

void NodeList::deleteNodeAt(int index)
{
    // checks if the index is not greater than last index
    if (index >= size)
    {
        cout << "\n!!!Index is out of range!!!\n";
        return;
    }
    // O(index); linear
    size--;
    Node *temp = this->head;

    // If the node is at the beginning then it replaces the head of list
    if (index == 0)
    {
        this->head = this->head->next;
        delete temp;
        return;
    }
    // traverses to one position before the node to delete
    index--;
    while (index--)
    {
        temp = temp->next;
    }

    // extracting the node
    Node *toDelete = temp->next;

    // If the node to delete is last node then
    if (toDelete->next == NULL)
    {
        // setting the second last node to NULL
        temp->next = NULL;
        // setting the end of list to the second last element so that it can add a new element
        tail = temp;
        return;
    }
    temp->next = temp->next->next;
    delete toDelete;
}

employee NodeList::elementAtIndex(int index)
{

    // O(index); linear
    if (index >= size)
    {
        cout << "\n!!!Index Out Of Range!!!\n";
        employee e;
        return e;
    }

    Node *temp = this->head;
    while (index--)
    { // traversomg to the desired index
        temp = temp->next;
    }

    return temp->data;
}

employee NodeList::elementAtStart()
{

    // O(1); constant
    if (head != NULL)
    { // if list is initialized then
        return head->data;
    }
    employee e;
    return e;
}

employee NodeList::elementAtEnd()
{
    // O(1); constant
    if (tail != NULL)
    { // if list is initialized then
        return tail->data;
    }
    employee e;
    return e;
}

int NodeList::sizeOfList()
{
    // O(1); constant
    return this->size;
}

employee NodeList::operator[](int i){
    return this->elementAtIndex(i);
}

int NodeList::find(int key){
    Node* temp = this->head; // creating a temporary pointer
    int index = 0; // setting an index counter
    while(temp != NULL){
        if(temp->data.id == key){ // checking if key matches to node data
            return index; // found
        }
        temp = temp->next; // traversing
        index++;
    }
    return -1; // not found
}