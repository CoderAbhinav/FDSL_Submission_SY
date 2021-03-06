#include <iostream>
#include "stacks.h"
using namespace std;

void printStack(stack);
int userSelection();

int main(){
    int selection = -1, inp;
    stack st;
    while (selection)
    {
        selection = userSelection();
        if(selection == 1){
            cout<<"Enter data\n>>> ";
            cin>>inp;
            st.push(inp);
        }else if(selection == 2){
            cout<<"\nPopping the top element";
            st.pop();
        }else if(selection == 3){
            cout<<"\nThe top Element is : "<<st.top();
        }else if(selection == 4){
            cout<<"\nHere is the stack";
            printStack(st);
        }else if(selection == 5){
            cout<<"\nStats for the given stack";
            cout<<"\nStack is "<<(st.isEmpty()? "":"not")<<" Empty.";
            cout<<"\nCurrent size of stack is "<<st.currentSize();
        }
    }
    

    return 0;
}

void printStack(stack st){
    cout<<"\n";
    while (!st.isEmpty())
    {
        cout<<st.top()<<"\n";
        st.pop();
    }
}

int userSelection(){
    cout<<"\n1. Push element";
    cout<<"\n2. Pop the top element";
    cout<<"\n3. Top element";
    cout<<"\n4. Print The Stack";
    cout<<"\n5. Statistics";
    cout<<"\n0. Exit System\n>>> ";
    int selection = 0;
    cin>>selection;
    return selection;
}