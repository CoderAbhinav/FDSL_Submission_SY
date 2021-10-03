#include <iostream>

class pointer
{
public:
    int getLength_ptr(char *);
    void strcpy_ptr(char *, char *);
    int compare_ptr(char *, char *);
    void reverse_ptr(char *);
    void add_ptr(char *, char *);
};

// return length of string
// O(n) -> n : size of string
int pointer::getLength_ptr(char *s)
{
    int i = 0;
    while (*s)
    {
        i++;
        s++;
    }
    return i;
}

// copy src to des
// O(n) -> n : size of src
void pointer:: strcpy_ptr(char *src, char *des)
{
    while (*src)
    {
        *des = *src;
        des++;
        src++;
    }
    *des = '\0'; // adding a terminating character so we don't get the garbage values
}

// returns difference between s1, s2
// O(n1 + n2) -> n1, n2 : lengths of s1, s2
int pointer::compare_ptr(char *s1, char *s2)
{
    return getLength_ptr(s1) - getLength_ptr(s2);
}


// reverse given string
// O(1.5n) -> n : length of string
void pointer:: reverse_ptr(char *s)
{
    char *end = s;
    while (*(end + 1))
    {
        end++;
    }
    while (s < end)
    {
        char temp = *s;
        *s = *end;
        *end = temp;
        s++;
        end--;
    }
}


// adds s2 at the end of s1
// O(n1+n2) -> n1, n2 : length of s1, s2
void pointer:: add_ptr(char *s1, char *s2)
{

    while (*s1)
    {
        s1++;
    }
    while (*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    // adding a terminating character so we don't get the garbage values
}