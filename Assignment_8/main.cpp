#include <iostream>
#include <string>
#define out(mode) if(mode)
using namespace std;


struct Item
{
    string itemName;
    int department;
    Item(){}
    Item(int dept, string name){
        this->itemName = name;
        this->department = dept;
    }
};

bool io = false;
void merge(Item*, int, int, int);
void mergeSort(Item*, int, int);

int main(){
    out(io) cout<<"Enter List Size\n>>> ";
    int n;
    cin>>n;
    Item itemArray[n];
    for(int i = 0; i < n; i++){
        string itemName;
        int deptNo;
        out(io) cout<<"Enter Details for Item No."<<i<<"\n>>> ";
        cin>>itemName>>deptNo;
        itemArray[i] = Item(deptNo, itemName);
    }

    mergeSort(itemArray, 0, n-1);

    cout<<"\n\nDept.No.\titem\n";
    for(int i = 0; i < n; i++){
        cout<<itemArray[i].department<<"\t"<<itemArray[i].itemName<<"\n";
    }
    return 0;
}

void merge(Item* a, int start, int mid, int end){
    /* creating arrays for storing 
    left and right part of mid*/
    int ls = mid - start + 1;
    int rs = end - mid;
    Item la[ls], ra[rs];
    
    // copying values
    for(int i = 0; i < ls; i++){
        la[i] = a[start + i];
    }
    for(int j = 0; j < rs; j++){
        ra[j] = a[mid + 1 + j];
    }

    // merging the arrays
    int i = 0, j = 0, k = start;
    while(i < ls && j < rs){
        if(la[i].department < ra[j].department){
            a[k] = la[i];
            i++;
        }else{
            a[k] = ra[j];
            j++;
        }
        k++;
    }

    while(i < ls){
        a[k] = la[i];
        k++; i++;
    }

    while(j < rs){
        a[k] = ra[j];
        k++; j++;
    }
}

void mergeSort(Item* a, int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}