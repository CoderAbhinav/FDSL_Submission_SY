#include <iostream>

class nopointer
{
public:
    int getLength(char *);
    void strcpy(char *, char *);
    int compare(char *, char *);
    void reverse(char *);
    void add(char *, char *);
};

// return length of string
// O(n) -> n : size of string
int nopointer::getLength(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

// copy src to des
// O(n) -> n : size of src
void nopointer::strcpy(char *src, char *des)
{
    int i = 0;
    while (src[i])
    {
        des[i] = src[i];
        i++;
    }
    des[i] = '\0'; // adding a terminating character so we don't get the garbage values
}

// returns difference between s1, s2
// O(n1 + n2) -> n1, n2 : lengths of s1, s2
int nopointer::compare(char *s1, char *s2)
{
    return getLength(s1) - getLength(s2);
}


// reverse given string
// O(1.5n) -> n : length of string
void nopointer::reverse(char *s)
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


// adds s2 at the end of s1
// O(n1+n2) -> n1, n2 : length of s1, s2
void nopointer::add(char *s1, char *s2)
{
    int i = 0;
    int dis = getLength(s1);
    while (s2[i])
    {
        s1[dis + i] = s2[i];
        i++;
    }
    s1[dis + i] = '\0';
    // adding a terminating character so we don't get the garbage values
}