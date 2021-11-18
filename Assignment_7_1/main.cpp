#include <iostream>
#include "Queue.h"
using namespace std;

int options();
void printQueue(Queue<int>&);


int main(){
    cout<<"Enter SIZE :\n>>> ";
    int n;
    cin>>n;
    Queue<int> q(n);
    int sel = -1, inp;
    while(sel){
        sel = options();
        if(sel == 1){
            try
            {
                cout<<"\nDATA\n>>> ";
                cin>>inp;
                q.enqueue(inp);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }else if(sel == 2){
            try
            {
                q.dequeue();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }else if(sel == 3){
            int front, back;
            try
            {
                front = q.front();
                back = q.back();
                cout<<"\nFRONT : "<<front<<"\nBACK : "<<back;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

            
        }else if(sel == 4){
            printQueue(q);
        }else if(sel == 5){
            cout<<"\nThe queue is "<<(q.isEmpty()? "":"not")<<" empty";
            cout<<"\nThe queue size is "<<q.size();
        }
    }
    return 0;
}

void printQueue(Queue<int> &q){
    int n = q.size();
    for(int i = 0; i < n; i++){  
        int data = q.front();
        cout<<data<<" ";
        q.dequeue();
        q.enqueue(data);
    }
}

int options(){
    cout<<"\n1. Enqueue";
    cout<<"\n2. Dequeue";
    cout<<"\n3. Front & Back";
    cout<<"\n4. Print Queue";
    cout<<"\n5. Statistics";
    cout<<"\n0. Exit\n>>> ";
    int sel;
    cin>>sel;
    return sel;
}