#include <iostream>
#include "LinkedList/NodeList.h"
#include "LinkedList/Node.h"
#define deb(x) cout << #x << "=" << x << endl
#define line cout<<"\n"


int options();


int main(){
    NodeList l;
    int selection = -1;
    while(selection){
        selection = options();
        if(selection == 1){
            l.insertAtBegin(cliToCreateEmployee());
        }else if(selection == 2){
            l.insertAtEnd(cliToCreateEmployee());
        }else if(selection == 3){
            cout<<"\nEnter Index : \n>>> ";
            int index;
            cin>>index;
            l.insertAt(index, cliToCreateEmployee());
        }else if(selection == 4){
            cout<<"\nEnter Index : \n>>> ";
            int index;
            cin>>index;
            l.deleteNodeAt(index);
        }else if(selection == 5){
            cout<<"\nEnter ID : \n>>> ";
            int id;
            cin>>id;
            int index = l.find(id);
            if(index != -1){
                employee temp = l.elementAtIndex(index);
                temp.printDetails();
            }
        }else if(selection == 6){
            cout<<"\nEnter INDEX : \n>>> ";
            int index;
            cin>>index;
            employee temp = l.elementAtIndex(index);
            if(temp.id != -1){
                temp.printDetails();
            }
        }else if(selection == 7){
            employee temp = l.elementAtStart();
            if(temp.id != -1){
                temp.printDetails();
            }
        }else if(selection == 8){
            employee temp = l.elementAtEnd();
            if(temp.id != -1){
                temp.printDetails();
            }
        }else if(selection == 9){
            l.printList();
        }

    }
    
    
    return 0;
}

int options(){
    cout<<"\n\n1.Add at begining";
    cout<<"\n2.Add at the end";
    cout<<"\n3.Add at index";
    cout<<"\n4.Delete Record at";
    cout<<"\n5.Search id";
    cout<<"\n6.Print employee At given index";
    cout<<"\n7.Print employee At Start";
    cout<<"\n8.Print employee At end";
    cout<<"\n9.Print all list";
    cout<<"\n0.Exit System\n>>> ";
    int inp;
    cin>>inp;
    return inp;
}

