#include <iostream>
#include "Node.h"
using namespace std;

class NodeList
{
private:
    Node *head;       // track head of list
    Node *end = NULL; // tracks the end of list
    int size;       // trcks the size of list

public:
    NodeList();
    ~NodeList();
    void printList(); // prints all list elements space separated
    void insertAtBegin(int data);
    void insertAtEnd(int data);
    void insertAt(int index, int data); // index from 0 to n; inserts at given index
    void deleteNodeAt(int index);       // delete node at index from 0 to n
    int elementAtIndex(int index);
    int elementAtStart();
    int elementAtEnd();
    int sizeOfList(); // returns size of list
};

NodeList::NodeList()
{
    // Worst Case O(1); constant
    this->head = this->end;
    size = 0;
}

NodeList::~NodeList()
{
}

void NodeList::printList()
{
    // O(size); linear
    Node *temp = this->head;
    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
}

void NodeList::insertAtBegin(int data)
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

void NodeList::insertAtEnd(int data)
{
    // O(1); constant
    size++;          // incrementing size
    if (end == NULL) // if the list is not initialized or the head == end == NULL
    {
        end = new Node; // allocating memory
        head = end;
        end->data = data;
    }
    else
    {
        end->next = new Node; // allocating memory to the next of end
        end = end->next;
        end->data = data;
    }
}

void NodeList::insertAt(int index, int data)
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
        end = toAdd;
    }
}

void NodeList::deleteNodeAt(int index)
{

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
        end = temp;
        return;
    }
    temp->next = temp->next->next;
    delete toDelete;
}

int NodeList::elementAtIndex(int index)
{

    // O(index); linear
    if (index > size)
    {
        cout << "\n!!!Index Out Of Range!!!\n";
        return -1;
    }

    Node *temp = this->head;
    while (index--)
    { // traversomg to the desired index
        temp = temp->next;
    }

    return temp->data;
}

int NodeList::elementAtStart()
{

    // O(1); constant
    if (head != NULL)
    { // if list is initialized then
        return head->data;
    }
    return -1;
}

int NodeList::elementAtEnd()
{
    // O(1); constant
    if (end != NULL)
    { // if list is initialized then
        return end->data;
    }
    return -1;
}

int NodeList::sizeOfList()
{
    // O(1); constant
    return this->size;
}
