#include <iostream>
#include "LinkedListINT.h"
using namespace std;

void solve();

int main(){
    int testCases;
    cin>>testCases;
    while (testCases--)
    {
        // cout<<"Hello\n";
        solve();
    }
    return 0;
}

void solve(){
    LinkedList l;
    int n, inp;
    string cmd;
    cin>>n;
    while(n--){
        cin>>cmd;
        if(cmd == "I"){
            cout<<((l.isEmpty())? "true":"false")<<"\n";
            continue;
        }else if(cmd == "AF"){
            cin>>inp;
            l.addFirst(inp);
        }else if(cmd == "AL"){
            cin>>inp;
            l.addLast(inp);
        }else if(cmd == "RF"){
            try
            {
                l.removeFirst();
            }
            catch(const std::exception& e)
            {
                cout << e.what() << '\n';
            }   
        }else if(cmd == "RL"){
            try
            {
                l.removeLast();
            }
            catch(const std::exception& e)
            {
                cout << e.what() << '\n';
            }
        }else if(cmd == "F"){
            try
            {
                cout<<l.first()<< '\n';
            }
            catch(const std::exception& e)
            {
                cout << e.what() << '\n';
            }
            continue;
            
        }else if(cmd == "L"){
            try
            {
                cout<<l.last()<< '\n';
            }
            catch(const std::exception& e)
            {
                cout << e.what() << '\n';
            }
            continue;
            
        }else if(cmd == "REV"){
            try
            {
                l.reverse();
            }
            catch(const std::exception& e)
            {
                cout << e.what() << '\n';
            }
            
        }
        printList(l);
        cout<<"\n";
    }
}