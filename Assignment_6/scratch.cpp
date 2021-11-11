#include <iostream>
#include "stacks.h"
using namespace std;

void printStack(stack);

int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
       
    printStack(st);
    st.push(40);
    printStack(st);
    
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