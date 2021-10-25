/*
* @CoderAbhinav
* @bried Assignment 1 Part 1 : Write string functions
* @author Abhinav Belhekar
* @Roll No : 224033
* @Batch : D2
* @Division : SY - D (Comp)
* @date 
*/

/*
Perform following string operations with and without pointers: 
1. Length 
2. Copy 
3. Concat 
4. Compare 
5. Reverse.
*/

#include <iostream>
#include "operations/pointer.h"
#include "operations/nopointer.h"

void UI();

int main()
{
    UI();
    return 0;
}




void UI()
{
    pointer ptr;
    nopointer noptr;
    std::cout << "Welcome, Presenting you simple string\n";
    char* s = new char;
    char* d = new char;
    char* e = new char;
    int sel = -1;
    while (sel != 0)
    {
        std::cout << "\n--------------------------------";
        std::cout << "\n1 -> Get Length Of Given String";
        std::cout << "\n2 -> Copy string to another array";
        std::cout << "\n3 -> Concatonate two strings";
        std::cout << "\n4 -> Compare two strings";
        std::cout << "\n5 -> Reverse given string";
        std::cout << "\n0 -> Exit the program.";
        std::cout << "\n> ";
        std::cin >> sel;
        std::cout << "You Selected " << sel << "\n";
        if (sel == 1)
        {
            std::cout << "\nEnter First string : ";
            std::cin.ignore();
            std::cin >> s;
            std::cout << "\nThe length of string (With Pointer) :" << s << " is = " << ptr.getLength_ptr(s);
            std::cout << "\nThe length of string (Without Pointer) :" << s << " is = " << noptr.getLength(s);
        }
        else if (sel == 2)
        {
            std::cout << "Enter String to Copy : ";
            std::cin.ignore();
            std::cin >> s;
            ptr.strcpy_ptr(s, d);
            std::cout << "The given string copied to array d\n";
            std::cout << "Here is the copied string (with pointer): " << d;
            noptr.strcpy(s,e);
            std::cout << "\nThe given string copied to array e\n";
            std::cout << "Here is the copied string (without pointer): " << d;
        }
        else if (sel == 3)
        {
            std::cout << "\nEnter First string : ";
            std::cin.ignore();
            std::cin >> s;
            char* temp = new char;
            noptr.strcpy(s, temp);
            std::cout << "\nEnter Second string : ";
            std::cin.ignore();
            std::cin >> d;
            ptr.add_ptr(s, d);
            noptr.add(temp, d);
            std::cout << "\nConcatonated string is (with pointer): " << s;
            std::cout << "\nConcatonated string is (without pointer): " << temp;
        }
        else if (sel == 4)
        {
            std::cout << "\nEnter First string : ";
            std::cin.ignore();
            std::cin >> s;
            std::cout << "\nEnter Second string : ";
            std::cin.ignore();
            std::cin >> d;
            int diff = noptr.compare(s, d);
            if (diff > 0)
            {
                std::cout << "\nFirst string has more character than second one.";
            }
            else if (diff < 0)
            {
                std::cout << "\nSecond string has more character than the first one.";
            }
            else
            {
                std::cout << "\nBoth strings are equal.";
            }
            std::cout << "Difference of character is : " << abs(diff);
        }
        else if (sel == 5)
        {
            std::cout << "Enter String to Reverse : ";
            std::cin.ignore();
            std::cin >> s;
            char* temp = new char;
            noptr.strcpy(s, temp);
            ptr.reverse_ptr(s);
            noptr.reverse(temp);
            std::cout << "\nReversed string is (with pointer): " << s;
            std::cout << "\nReversed string is (with pointer): " << temp;
        }
        std::cout<<std::endl;

    }
    std::cout << "Exited!";
}
