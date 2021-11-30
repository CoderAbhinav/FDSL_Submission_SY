#include <iostream>
using namespace std;

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int main(){
    int n = 10;
    // cin>>n;
    int arr[] = {6, 5, 8, 9, 9, 1, 7, 6, 1, 7};
    // for(int i = 0; i < n; i++){
    //     cin>>arr[i];
    // }

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void merge(int* a, int start, int mid, int end){
    /* creating arrays for storing 
    left and right part of mid*/
    int ls = mid - start + 1;
    int rs = end - mid;
    int la[ls], ra[rs];
    
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
        if(la[i] < ra[j]){
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

void mergeSort(int* a, int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}