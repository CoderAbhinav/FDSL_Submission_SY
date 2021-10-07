#include <iostream>
#include "database/employee.h"
using namespace std;

int displayOptions()
{
    int option;
    cout<<"\nOPTIONS";
    cout<<"\n1 -> ADD A NEW ENTRY";
    cout<<"\n2 -> DISPLAY DATABASE";
    cout<<"\n3 -> SEARCH RECORD";
    cout<<"\n4 -> DELETE RECORD";
    cout<<"\n0 -> EXIT SYSTEM";
    cout<<"\n>>> ";
    cin>>option;
    return option;
}


Employee createEmployee()
{
    Employee e;
    cout<<"\nEMPLOYEE";
    cout<<"\nID      :\n>>> ";
    cin>>e.id;
    cout<<"\nNAME    :\n>>> ";
    cin>>e.name;
    cout<<"\nSALARY  :\n>>> ";
    cin>>e.salary;
    return e;
}

void printThisEmployeeDetail(Employee e)
{
    cout<<"\nEMPLOYEE DETAILS";
    cout<<"\nID      : "<<e.id;
    cout<<"\nNAME    : "<<e.name;
    cout<<"\nSALARY  : "<<e.salary;
}