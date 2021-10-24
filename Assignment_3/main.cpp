#include <iostream>
#include "Matrix/Operations.h"
using namespace std;

int options();

int main(){

    Operations op;

    int selection = -1;
    while (selection)
    {
        selection = options();
        if(selection == 1){
            cout<<"Enter Number Of Rows, Column\n>>> ";
            int row, col;
            cin>>row>>col;
            op = Operations(row, col);
        }
        else if(selection == 2){
            cout<<"\nStart Entering the matrix";
            op.takeInput();
            cout<<"\nInput Completed";
            op.printSparse();

        }
        else if(selection == 3){
            op.resetMatrix();
        }
        else if(selection == 4){
            Operations temp = op.simpleTranspose();
            cout<<"\nHere is your sparse matrix";
            temp.printSparse();
        }
        else if(selection == 5){
            Operations temp = op.fastTranspose();
            cout<<"\nHere is your sparse matrix";
            temp.printSparse();
        }
    }
    

    return 0;    
}

int options(){
    cout<<"\n\n::::::::::::::::::::::";
    cout<<"\n::::SPARSE MATRIX:::::";
    cout<<"\n::::::::::::::::::::::";
    cout<<"\n1.create matrix";
    cout<<"\n2.set matrix";
    cout<<"\n3.reset matrix";
    cout<<"\n4.simple transpose";
    cout<<"\n5.fast transpose";
    cout<<"\n0.Exit";
    cout<<"\n>>> ";
    int n;
    cin>>n;
    return n;
}