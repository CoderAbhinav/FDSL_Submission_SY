#pragma once
#include <iostream>
#include <string>
using namespace std;
struct employee{
    int id = -1;
    double salary;
    string name;
    void printDetails();
};

struct Node
{
    employee data;
    Node* next = NULL;
};


void employee::printDetails(){
    cout<<"\nID : "<<id<<"\tNAME : "<<name<<"\tSALARY : "<<salary;
}

employee createEmployee(int id, string name, double salary){
    employee e;
    e.id = id;
    e.salary = salary;
    e.name = name;
    return e;
}

employee cliToCreateEmployee(){
    employee e;
    cout<<"\nEnter ID :\n>>> ";
    cin>>e.id;
    cout<<"\nEnter NAME :\n>>> ";
    cin>>e.name;
    cout<<"\nEnter SALARY :\n>>> ";
    cin>>e.salary;
    return e;
}