#include <iostream>
#include "Matrix/Operations.h"
using namespace std;

int main(){
    int row, col;
    cin>>row>>col;
    Operations op(row, col);
    op.takeInputs();
    op.printSparse();
    Operations temp = op.fastTranspose();
    temp.printSparse();
    cout<<"DONE INPUTS";
    return 0;
}