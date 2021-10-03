/*
@Author : Sarvadnya Chiddarwar
@PRN No : 22010770
@Roll No : 224025
@Assignment1 : Perform following string operations with and without pointers: 1. Length 2. Copy 3.Concat 4. Compare 5.Reverse.
*/

#include <iostream>
#include <cstring>
using namespace std;

//Declaring functions
void len(char s[50]);
void len_ptr(char *s_ptr);
void cpy(char s[50]);
void cpy_ptr(char *s_ptr1, char *s_ptr2);
void concat(char s1[50], char s2[50]);
void concat_ptr(char *s_ptr1, char *s_ptr2, char *s_ptr3);
void cmp(char s1[50], char s2[50]);
int cmp_ptr(char *s_ptr1, char *s_ptr2);
void rev(char s[50]);
void rev_ptr(char *s_ptr);

//Main program
int main()
{
    //declaring variables
    char str1[50], str2[50], strCpy[50], strCon[100], yn;
    int n, flag_cmp;
    bool b = true;
    //Using while loop for running code continuosly
    while (b)
    {
        cout << "STRING OPERATIONS :" << endl;
        cout << "1.LENGTH" << endl;
        cout << "2.COPY" << endl;
        cout << "3.CONCATENATE" << endl;
        cout << "4.COMAPRE" << endl;
        cout << "5.REVERSE" << endl;
        cout << "ENTER CHOICE : ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "ENTER STRING : ";
            cin >> str1;
            cout << "\n";
            len(str1);
            len_ptr(str1);
            break;
        case 2:
            cout << "ENTER STRING : ";
            cin >> str1;
            cout << "\n";
            cpy(str1);
            cpy_ptr(str1, strCpy);
            cout << "COPIED STRING WITH POINTER : " << strCpy << endl;
            break;
        case 3:
            cout << "ENTER STRING 1 : ";
            cin >> str1;
            cout << "ENTER STRING 2 : ";
            cin >> str2;
            cout << "\n";
            concat(str1, str2);
            concat_ptr(str1, str2, strCon);
            cout << "CONCATENATED STRING WITH POINTER : " << strCon << endl;
            break;
        case 4:
            cout << "ENTER STRING 1 : ";
            cin >> str1;
            cout << "ENTER STRING 2 : ";
            cin >> str2;
            cout << "\n";
            cmp(str1, str2);
            flag_cmp = cmp_ptr(str1, str2);
            if (flag_cmp == 0)
            {
                cout << "COMPARING STRING WITH POINTER : " << str1 << " NOT EQUAL TO " << str2 << endl;
            }
            else if (flag_cmp == 1)
            {
                cout << "COMPARING STRING WITH POINTER : " << str1 << " EQUAL TO " << str2 << endl;
            }
            break;
        case 5:
            cout << "ENTER STRING : ";
            cin >> str1;
            cout << "\n";
            rev(str1);
            rev_ptr(str1);
            cout << "REVERSED STRING WITH POINTER : " << str1 << endl;
            break;

        default:
            cout << "INVALID INPUT!!";
            break;
        }
        cout << "DO YOU WANT TO CONTINUE (y/n)" << endl;
        cin >> yn;
        if (yn == 'y')
        {
            b = true;
        }
        else if (yn == 'n')
        {
            b = false;
        }
        else
        {
            cout << "\nInvalid!!" << endl;
            b = false;
        }
        cout << "\n";
    }
}

void len(char s[50])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    cout << "LENGTH OF STRING WITHOUT POINTER : " << i << endl;
}
void len_ptr(char *s_ptr)
{
    int i = 0;
    while (*s_ptr != '\0')
    {
        i++;
        s_ptr++;
    }
    cout << "LENGTH OF STRING WITH POINTER : " << i << endl;
}

void cpy(char s[50])
{
    char copy[50];
    int i = 0;
    while (s[i] != '\0')
    {
        copy[i] = s[i];
        i++;
    }
    cout << "COPIED STRING WITHOUT POINTER : " << copy << endl;
}
void cpy_ptr(char *s_ptr1, char *s_ptr2)
{
    char copy[50];
    while (*s_ptr1 != '\0')
    {
        *s_ptr2 = *s_ptr1;
        s_ptr1++;
        s_ptr2++;
    }
}

void concat(char s1[50], char s2[50])
{
    char s[100];
    int i = 0;
    int j = 0;
    while (s1[i] != '\0')
    {
        s[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        s[i] = s2[j];
        j++;
        i++;
    }
    cout << "CONCATENATED STRING WITHOUT POINTER : " << s << endl;
}
void concat_ptr(char *s_ptr1, char *s_ptr2, char *s_ptr3)
{
    while (*s_ptr1 != '\0')
    {
        *s_ptr3 = *s_ptr1;
        s_ptr1++;
        s_ptr3++;
    }
    while (*s_ptr2 != '\0')
    {
        *s_ptr3 = *s_ptr2;
        s_ptr2++;
        s_ptr3++;
    }
}

void cmp(char s1[50], char s2[50])
{
    int flag = 1;
    if (strlen(s1) == strlen(s2))
    {
        for (int i = 0; i < strlen(s1); i++)
        {
            if (s1[i] == s2[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }
    else
    {
        flag = 0;
    }

    if (flag == 0)
    {
        cout << "COMPARING STRING WITHOUT POINTER : " << s1 << " NOT EQUAL TO " << s2 << endl;
    }
    else if (flag == 1)
    {
        cout << "COMPARING STRING WITHOUT POINTER : " << s1 << " EQUAL TO " << s2 << endl;
    }
}
int cmp_ptr(char *s_ptr1, char *s_ptr2)
{
    int l1=strlen(s_ptr1);
    int l2=strlen(s_ptr2);
    cout << *s_ptr1 << *s_ptr2;
    int flag = 1;
    if (l1 == l2)
    {
        for (int k = 0; k < l1; k++)
        {
            if (*s_ptr1 != *s_ptr2)
            {
                return 0;
            }
            s_ptr1++;
            s_ptr2++;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void rev(char s[50])
{
    int len = strlen(s);
    char rev[50];
    for (int i = 0; i < len; i++)
    {
        rev[i] = s[len - i - 1];
    }
    cout << "REVERSED STRING WITHOUT POINTER : " << rev << endl;
}
void rev_ptr(char *s_ptr)
{
    int l = 0;
    char *start_ptr, *end_ptr, temp;
    start_ptr = s_ptr;
    end_ptr = s_ptr;
    while (*s_ptr != '\0')
    {
        l++;
        s_ptr++;
    }  
    for (int i = 0; i < l - 1; i++)
        end_ptr++;
    for (int i = 0; i < l / 2; i++) {
        temp = *end_ptr;
        *end_ptr = *start_ptr;
        *start_ptr = temp;
  
        start_ptr++;
        end_ptr--;
    }
}