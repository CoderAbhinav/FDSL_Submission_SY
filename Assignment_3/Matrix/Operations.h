#include <iostream>
#include <iomanip>
#include "SparseMatrix.h"
#define deb(x) cout << #x << "=" << x << endl
using namespace std;

class Operations
{
private:
    /* data */
    int row_count;
    int col_count;
public:
    int val_count = 0;
    SparseMatrix *sparseMatrix;
    Operations();
    Operations(int row, int col);
    ~Operations();
    void takeInputs();
    void printSparse();
    Operations simpleTranspose();
    Operations fastTranspose();
};

Operations::Operations(int row, int col)
{
    this->row_count = row;
    this->col_count = col;
}

Operations::~Operations()
{
}

void Operations::takeInputs()
{
    SparseMatrix *temp = new SparseMatrix[this->row_count * this->col_count + 1];
    int inp;
    int pos = 0;
    for (int i = 0; i < this->row_count; i++)
    {
        for (int j = 0; j < this->col_count; j++)
        {
            cin >> inp;
            if (inp != 0)
            {
                temp[pos].row = i;
                temp[pos].col = j;
                temp[pos].val = inp;
                this->val_count++;
                pos++;
            }
        }
    }
    sparseMatrix = new SparseMatrix[this->val_count + 1];
    sparseMatrix[0].row = row_count;
    sparseMatrix[0].col = col_count;
    sparseMatrix[0].val = val_count;
    for (int i = 0; i < this->val_count; i++)
    {
        sparseMatrix[i + 1].row = temp[i].row;
        sparseMatrix[i + 1].col = temp[i].col;
        sparseMatrix[i + 1].val = temp[i].val;
    }
}

void Operations::printSparse()
{
    cout <<std::left<<setw(4) << "ROW" << setw(4) << "COL" << setw(4) << "VAL"
         << "\n";
    for (int i = 0; i <= this->val_count; i++)
    {
        cout << setw(4) << sparseMatrix[i].row << setw(4) << sparseMatrix[i].col << setw(4) << sparseMatrix[i].val
             << "\n";
    }
}


Operations Operations::simpleTranspose(){
    Operations temp(this->row_count, this->col_count);
    temp.val_count = this->val_count;
    temp.sparseMatrix = new SparseMatrix[this->sparseMatrix[0].val+1];
    int vals, pos = 1;
    temp.sparseMatrix[0].row = this->sparseMatrix->row;
    temp.sparseMatrix[0].col = this->sparseMatrix->col;
    temp.sparseMatrix[0].val = this->sparseMatrix->val;
    vals = this->sparseMatrix[0].val;

    if(vals>0){
        for(int i = 0; i < (this->sparseMatrix[0].col); i++){
            for(int j = 0; j <= vals; j++){
                if(this->sparseMatrix[j].col == i){
                    temp.sparseMatrix[pos].col = this->sparseMatrix[j].row;
                    temp.sparseMatrix[pos].row = this->sparseMatrix[j].col;
                    temp.sparseMatrix[pos].val = this->sparseMatrix[j].val;
                    pos++;
                }
            }
        }
    }
    return temp;
}

Operations fastTranspose(){
    
}
