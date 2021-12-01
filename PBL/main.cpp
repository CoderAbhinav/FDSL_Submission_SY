#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    LinkedList<int> l;
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
    return 0;
}