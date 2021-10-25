#include <iostream>
#include "Matrix/Operations.h"
using namespace std;


int main(){

    cout<<"\nEnter Row & Column Size\n>>> ";
    int row, col;
    cin>>row>>col;
    Operations op(row, col);
    cout<<"\nStart Entering Input \n";
    op.takeInput();
    cout<<"\nInput Completed\nHere what we got !\n";
    op.printSparse();
    cout<<"\nHere is Simple Transpose\n";
    op.simpleTranspose().printSparse();
    cout<<"\nHere is fast Transpose\n";
    op.fastTranspose().printSparse();    
    return 0;    
}

