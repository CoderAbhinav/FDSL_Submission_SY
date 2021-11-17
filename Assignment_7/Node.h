#pragma once
#include <iostream>

template <typename T>
class Node
{
    public:
    T data;
    Node* next = NULL;
    Node();
    Node(T data);
};

template <typename T>
Node<T>::Node(T data){
    this->data = data;
}

