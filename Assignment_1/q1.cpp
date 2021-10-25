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

int getLength(char *);
void strcpy(char *, char *);
int compare(char *, char *);
void reverse(char *);
void add(char *, char *);
void UI();

int main()
{
    UI();
    return 0;
}

int getLength(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

void strcpy(char *src, char *des)
{
    int i = 0;
    while (src[i])
    {
        des[i] = src[i];
        i++;
    }
    des[i] = '\0'; // adding a terminating character so we don't get the garbage values
}

int compare(char *s1, char *s2)
{
    return getLength(s1) - getLength(s2);
}

void reverse(char *s)
{
    int high = getLength(s) - 1;
    int low = 0;
    while (low < high)
    {
        char temp = s[high];
        s[high] = s[low];
        s[low] = temp;
        high--;
        low++;
    }
}

void reverse_ptr(char *s)
{
    char* end = s;
    while(*(end+1))
    {
        end++;
    }
    while (s<end)
    {
        char temp = *s;
        *s = *end;
        *end = temp;
        s++;
        end--;
    }
}

void add(char *s1, char *s2)
{
    int i = 0;
    int dis = getLength(s1);
    while (s2[i])
    {
        *(s1 + dis + i) = s2[i];
        i++;
    }
    *(s1 + dis + i) = '\0'; // adding a terminating character so we don't get the garbage values
}

void UI()
{
    std::cout << "Welcome, Presenting you simple string\n";
    char* s = new char;
    char* d = new char;
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
        // std::cin.ignore();
        std::cin >> sel;
        std::cout << "You Selected " << sel << "\n";
        if (sel == 1)
        {
            std::cout << "\nEnter First string : ";
            std::cin.ignore();
            std::cin >> s;
            std::cout << "\nThe length of string " << s << " is = " << getLength(s);
        }
        else if (sel == 2)
        {
            std::cout << "Enter String to Copy : ";
            std::cin.ignore();
            std::cin >> s;
            strcpy(s, d);
            std::cout << "The given string copied to array d\n";
            std::cout << "Here is the copied string : " << d;
        }
        else if (sel == 3)
        {
            std::cout << "\nEnter First string : ";
            std::cin.ignore();
            std::cin >> s;
            std::cout << "\nEnter Second string : ";
            std::cin.ignore();
            std::cin >> d;
            add(s, d);
            std::cout << "\nConcatonated string is : " << s;
        }
        else if (sel == 4)
        {
            std::cout << "\nEnter First string : ";
            std::cin.ignore();
            std::cin >> s;
            std::cout << "\nEnter Second string : ";
            std::cin.ignore();
            std::cin >> d;
            int diff = compare(s, d);
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
            reverse_ptr(s);
            std::cout << "\nReversed string is : " << s;
        }

    }
    std::cout << "Exited!";
}
