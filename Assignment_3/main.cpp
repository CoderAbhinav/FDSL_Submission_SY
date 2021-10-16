#include <iostream>
#include "Matrix/Operations.h"
using namespace std;

int main(){
    int row, col;
    cin>>row>>col;
    Operations op(row,col);


    op.takeInput();
    

    op.printSparse();
    cout<<"\n\n";
    Operations temp = op.simpleTranspose();
    temp.printSparse();
    return 0;
}