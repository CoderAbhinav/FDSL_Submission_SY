#include <iostream>
#include <iomanip>
#include "SparseMatrix.h"

using namespace std;

class Operations
{
private:
    SparseMatrix* sparseMatrix; // main sparse matrix variable
    // matrix parameteres
    int col_count;
    int row_count;
    int val_count = 0;
    // flag
    bool matrixCreated = false;

public:
    Operations(int, int);
    Operations();
    ~Operations();

    void takeInput(); // taking row x col input
    void printSparse(); // print the sparse matrix
    void resetMatrix();
    Operations simpleTranspose();
    Operations fastTranspose();
};

Operations::Operations(int row_count, int col_count)
{
    // takes the size of standard matrix
    this->row_count = row_count;
    this->col_count = col_count;
}

Operations::~Operations()
{
}

void Operations::resetMatrix(){
    this->matrixCreated = false;
}

void Operations::takeInput(){

    // if(matrixCreated) return; // if the values are already there it will not take input

    // creating a sparse matrix of size row x col
    SparseMatrix *temp = new SparseMatrix[this->row_count * this->col_count + 1]; 

    int inp, pos = 0; // inp for storing input & pos points to the current position of temp
    for (int i = 0; i < this->row_count; i++)
    {
        for (int j = 0; j < this->col_count; j++)
        {
            cin >> inp;
            if (inp != 0) // checking if there is non zero value
            {
                temp[pos] = createSparseMatrix(i, j, inp);
                this->val_count++;
                pos++;
            }
        }
    }
    this->sparseMatrix = new SparseMatrix[this->val_count + 1]; // allocating a sparse
    // allocating the first location with col, row, total vals
    this->sparseMatrix[0] = createSparseMatrix(row_count, col_count, val_count);
  
    // copying the non-zero values to main sparse matix
    for (int i = 0; i < this->val_count; i++)
    {
        this->sparseMatrix[i+1] = createSparseMatrix(temp[i].row, temp[i].col, temp[i].val);
       
    }
    matrixCreated = true;
}


void Operations::printSparse()
{
    if(!matrixCreated) return;
    cout <<std::left<<setw(4) << "ROW" << setw(4) << "COL" << setw(4) << "VAL"
         << "\n";
    for (int i = 0; i <= this->sparseMatrix[0].val; i++)
    {
        cout << setw(4) << sparseMatrix[i].row << setw(4) << sparseMatrix[i].col << setw(4) << sparseMatrix[i].val
             << "\n";
    }
}


Operations Operations::simpleTranspose(){
    // creating an object to return the operation
    Operations rev(this->col_count, this->row_count);
    // allocating memory
    rev.sparseMatrix = new SparseMatrix[this->val_count+1]; 
    // setting the row, col, val count & interchaning row & cols
    rev.sparseMatrix[0] = createSparseMatrix(this->col_count, this->row_count, this->val_count); 
    // cheking if values exist
    int vals = this->val_count, pos = 1;
    
    if(vals>0){
        for(int i = 0 ; i < this->col_count; i++){
            for(int j = 0; j <= this->val_count; j++){
                if(this->sparseMatrix[j].col == i){ // checks if given col matches
                    SparseMatrix temp = this->sparseMatrix[j];
                    
                    rev.sparseMatrix[pos] = createSparseMatrix(temp.col, temp.row, temp.val); // interchanging row and cols
                    pos++;
                }
            }
        }
    }
    rev.matrixCreated = true; // setting the flag to true
    return rev;   

}