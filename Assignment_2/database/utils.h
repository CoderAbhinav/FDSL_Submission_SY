
#include <iostream>
#include "employee.h"

int binarySearch(Employee arr[], int start, int end, int key)
{
    if(end>=start)
    {
        int mid = (start+end)/2;
        if(arr[mid].id == key)
        {
            return mid;
        }
        else if(arr[mid].id < key)
        {
            return binarySearch(arr, mid+1, end, key);
        }
        else{
            return binarySearch(arr, start, mid-1, key);
        }

    }
    return -1;
}

int getPerfectPosition(Employee arr[], int total_elements, Employee e)
{
    int pos = 0;
    while(pos < total_elements)
    {
        if(e.id >= arr[pos].id)
        {
            pos++;
        }
        else
        {
            break;
        }
    }
    return pos;
}
void shiftPlaceAndInsertForward(int target_pos, int total_elements,  Employee arr[],Employee e){
    Employee prev = arr[target_pos];
    Employee next;
    arr[target_pos] = e;
    int pos = target_pos+1;
    while (pos <= total_elements)
    {
        next = arr[pos];
        arr[pos] = prev;
        prev = next;
        pos++;
    }
    
}


void shiftEntriesBackward(int target_pos, int total_elements,  Employee arr[])
{

    Employee cur = arr[total_elements-1];
    Employee next;

    int pos = total_elements-1;

    while(target_pos <= pos)
    {
        next = arr[pos];
        arr[pos] = cur;
        cur = next;
        pos--;

    }
}